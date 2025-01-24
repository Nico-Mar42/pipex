/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:22:16 by draask            #+#    #+#             */
/*   Updated: 2025/01/24 16:07:46 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nb_cmd)
	{
		free(data->cmds[i]);
		i++;
	}
	free(data->cmds);
	if (data->nb_cmd > 1)
	{
		j = 0;
		while (j < data->nb_cmd - 1)
		{
			free(data->pipe_fd[j]);
			j++;
		}
		free(data->pipe_fd);
	}
	free(data->children);
	free(data->infile);
	free(data->outfile);
	free(data);
}

void	free_str_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	error(int error, t_data *data, t_child *child)
{
	if (error == 1)
	{
		perror("open error");
		close_pipe(data);
	}
	if (error == 2)
	{
		perror("path error");
		free_str_array(child->args);
		free(child);
	}
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
