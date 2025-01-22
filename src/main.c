/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:26:07 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/22 17:34:10 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_data *data, int i, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		j;
	char	**args;
	char	*path;

	if (i == 0)
	{
		fd_in = open(data->infile, O_RDONLY);
		//error gestion
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(data->pipe_fd[0][1], STDOUT_FILENO);
	}
	else if (i == data->nb_cmd - 1)
	{
		dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
		fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		//error gestion
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}	
	else
	{
		dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(data->pipe_fd[i][1], STDOUT_FILENO);
	}
	j = 0;
	while (j < data->nb_cmd - 1)
	{
		close(data->pipe_fd[j][0]);
		close(data->pipe_fd[j][1]);
		j++;
	}
	
	args = ft_split(data->cmds[i], ' ');
	//error gestion
	path = get_path(args[0], envp);
	if (execve(path, args, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	free(path);
	free_str_array(args);
}

void exec_process(t_data *data, char **envp)
{
	int i = 0;
	pid_t pid;

	data->children = malloc(data->nb_cmd * sizeof(pid_t));
	// error gestion

	while (i < data->nb_cmd)
	{
		pid = fork();
		//gestion error
		if (pid == 0)
			child_process(data, i, envp);
		else
			data->children[i] = pid;
		i++;
	}
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**all_path;

	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			all_path = ft_split(&envp[i][6], ':');
		i++;
	}
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (all_path[i])
	{
		path = ft_strjoin(all_path[i], cmd);
		if (access((const char *)path, F_OK) == 0)
			{
				free_str_array(all_path);
				return (path);
			}
		i++;
	}
	return (free(path), free_str_array(all_path), NULL);
}

int	main(int argc, char const *argv[], char **envp)
{
	t_data	*data;


	data = malloc(sizeof(t_data));
	data->infile = ft_strdup(argv[1]);
	data->outfile = ft_strdup(argv[argc - 1]);
	//gestion error
	parse_cmd(&data, argc, (char **)argv);
	
	open_pipe(&data);
	
	exec_process(data, envp);

	close_parent_pipes(data);

	wait_children(data);
	
	free_data(data);
	return (0);
}

