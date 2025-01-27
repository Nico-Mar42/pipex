/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:22:16 by draask            #+#    #+#             */
/*   Updated: 2025/01/27 11:05:50 by nicolmar         ###   ########.fr       */
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
