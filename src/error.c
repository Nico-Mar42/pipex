/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:05:53 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/27 11:21:14 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int error, t_data *data, t_child *child)
{
	if (error == 1)
		close_pipe(data);
	if (error == 2)
		perror("path error");
	if (error == 3)
	{
		perror("execve");
		free_str_array(child->args);
		free(child->path);
		free(child);
	}
	if (error == 4)
		perror("fork error");
	free_data(data);
	exit(EXIT_FAILURE);
}

int	fd_open(t_data *data, char *file, int in_out)
{
	int	fd;

	if (in_out == 0)
		fd = open(file, O_RDONLY);
	if (in_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(file);
		error(1, data, NULL);
	}
	return (fd);
}

void	path_error(t_child *child, t_data *data)
{
	free(child->path);
	free_str_array(child->args);
	free(child);
	error(2, data, NULL);
}
