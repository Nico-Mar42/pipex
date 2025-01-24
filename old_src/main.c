/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:26:07 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/22 16:55:38 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_tcmd(t_cmd **data, char *path)
{
	int i;

	i = -1;
	while((*data)->cmd_arg[++i])
		free((*data)->cmd_arg[i]);
	free((*data)->cmd_arg);
	i = -1;
	while((*data)->path[++i])
		free((*data)->path[i]);
	free((*data)->path);
	free(*data);
	free(path);
}

char *get_path(t_cmd **s_cmd, char **envp, char *cmd)
{
	int i;
	char	*path;
	char	*tmp_cmd;

	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			(*s_cmd)->path = ft_split(&envp[i][6], ':');
		i++;
	}
	i = 0;
	tmp_cmd = ft_strjoin("/", cmd);
	while ((*s_cmd)->path[i])
	{
		path = ft_strjoin((*s_cmd)->path[i], (const char *)tmp_cmd);
		if (access(path, F_OK) == 0)
			return (free(tmp_cmd), path);
		free (path);
		i++;
	}
	free(tmp_cmd);
	return (NULL);
}

void child_1(t_data **data, char **envp, char *cmd)
{
	t_cmd *s_cmd;
	char *path;

	s_cmd = malloc(sizeof(t_cmd));
	s_cmd->cmd_arg = ft_split(cmd, ' ');
	path = get_path(&s_cmd, envp, s_cmd->cmd_arg[0]);
	ft_printf("path = %s\n", path);
	(*data)->child1 = fork();
	if	((*data)->child1 == -1)
	{
		perror("erreur fork");
		exit (1);
	}
	if ((*data)->child1 == 0)
	{
		dup2((*data)->pipe_fd[1], STDOUT_FILENO);
		dup2((*data)->fd_in, STDIN_FILENO);
		close((*data)->pipe_fd[0]);
		if (execve(path, s_cmd->cmd_arg, envp) == -1)
		{
			ft_printf("execve failed: %s\n");
			exit(1);
		}
	}
	close((*data)->fd_in);
	free_tcmd(&s_cmd, path);
}

void child_2(t_data **data, char **envp, char *cmd)
{
	t_cmd *s_cmd2;
	char *path;

	s_cmd2 = malloc(sizeof(t_cmd));
	s_cmd2->cmd_arg = ft_split(cmd, ' ');
	path = get_path(&s_cmd2, envp, s_cmd2->cmd_arg[0]);
	(*data)->child2 = fork();
	if	((*data)->child2 == -1)
	{
		perror("erreur fork");
		exit (1);
	}
	if ((*data)->child2 == 0)
	{
		dup2((*data)->pipe_fd[0], STDIN_FILENO);
		dup2((*data)->fd_out, STDOUT_FILENO);
		close((*data)->pipe_fd[1]);
		if (execve(path, s_cmd2->cmd_arg, envp) == -1)
		{
			ft_printf("execve failed: %s\n");
			exit(1);
		}
	}
	close((*data)->fd_out);
	free_tcmd(&s_cmd2, path);
}

int	main(int argc, char const *argv[], char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc < 5)
		return 0;

	pipe(data->pipe_fd);
	data->fd_in = open(argv[1], O_RDONLY);
	data->fd_out = open(argv[4], O_WRONLY);
	
	child_1(&data, envp, (char *)argv[2]);
	child_2(&data, envp, (char *)argv[3]);

	dup2(data->pipe_fd[0], 0);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid(data->child1, NULL, 0);
	waitpid(data->child2, NULL, 0);
	
	free(data);
	return (0);
}


