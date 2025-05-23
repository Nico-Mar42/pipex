/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:52:50 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/27 11:20:54 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_child(t_data *data, char **envp, int i)
{
	int		fd_in;
	t_child	*child1;

	fd_in = fd_open(data, data->infile, 0);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(data->pipe_fd[0][1], STDOUT_FILENO);
	close_pipe(data);
	child1 = malloc(sizeof(t_child));
	child1->args = ft_split(data->cmds[i], ' ');
	if (ft_strchr(child1->args[0], '/') == NULL)
		child1->path = get_path(child1->args[0], envp);
	else
		child1->path = (ft_strdup(child1->args[0]));
	if (child1->path == NULL)
		path_error(child1, data);
	if (execve(child1->path, child1->args, envp) == -1)
		error(3, data, child1);
	
}

void	last_child(t_data *data, char **envp, int i)
{
	int		fd_out;
	t_child	*child2;

	dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
	fd_out = fd_open(data, data->outfile, 1);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close_pipe(data);
	child2 = malloc(sizeof(t_child));
	child2->args = ft_split(data->cmds[i], ' ');
	if (ft_strchr(child2->args[0], '/') == NULL)
		child2->path = get_path(child2->args[0], envp);
	else
		child2->path = (ft_strdup(child2->args[0]));
	if (child2->path == NULL)
		path_error(child2, data);
	if (execve(child2->path, child2->args, envp) == -1)
		error(3, data, child2);

}

void	int_child(t_data *data, char **envp, int i)
{
	t_child	*child3;

	dup2(data->pipe_fd[i - 1][0], STDIN_FILENO);
	dup2(data->pipe_fd[i][1], STDOUT_FILENO);
	close_pipe(data);
	child3 = malloc(sizeof(t_child));
	child3->args = ft_split(data->cmds[i], ' ');
	if (ft_strchr(child3->args[0], '/') == NULL)
		child3->path = get_path(child3->args[0], envp);
	else
		child3->path = (ft_strdup(child3->args[0]));
	if (child3->path == NULL)
		path_error(child3, data);
	if (execve(child3->path, child3->args, envp) == -1)
		error(3, data, child3);

}
