/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:26:07 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/24 16:22:45 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_data *data, int i, char **envp)
{
	if (i == 0)
		first_child(data, envp, i);
	else if (i == data->nb_cmd - 1)
		last_child(data, envp, i);
	else
		int_child(data, envp, i);
}

void	exec_process(t_data *data, char **envp)
{
	int		i;
	pid_t	pid;

	i = 0;
	//if (ft_strncmp(".tmp.txt", data->infile, 9) == 0)
	//	i++;
	data->children = malloc(data->nb_cmd * sizeof(pid_t));
	while (i < data->nb_cmd)
	{
		pid = fork();
		if (pid == -1)
			error(4, NULL, NULL);
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
	while (envp[i])
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

	if (argc < 5)
		exit(EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	data->here_doc = 0;
	if (ft_strncmp("here_doc", argv[1], 9) != 0)
	data->infile = ft_strdup(argv[1]);
	else 
	{
		data->infile = ft_strdup(here_doc((char *)argv[2]));
		data->here_doc = 1;
	}
	data->outfile = ft_strdup(argv[argc - 1]);
	parse_cmd(&data, argc, (char **)argv);
	open_pipe(&data);
	exec_process(data, envp);
	close_parent_pipes(data);
	wait_children(data);
	if (data->here_doc == 1)
		unlink(".tmp.txt");
	free_data(data);
	return (0);
}
