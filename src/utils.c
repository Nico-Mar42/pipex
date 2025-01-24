/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:20:02 by draask            #+#    #+#             */
/*   Updated: 2025/01/24 16:15:07 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parse_cmd(t_data **data, int argc, char **argv)
{
	int	i;
	
	i = 0;
	if ((*data)->here_doc == 0)
	{
		(*data)->nb_cmd = argc - 3;
		(*data)->cmds = malloc(((*data)->nb_cmd + 1) * sizeof(char *));
		while (i <= (*data)->nb_cmd - 1)
		{
			(*data)->cmds[i] = ft_strdup(argv[i + 2]);
			i++;
		}
		(*data)->cmds[i] = NULL;
	}
	else
	{
		(*data)->nb_cmd = argc - 4;
		(*data)->cmds = malloc(((*data)->nb_cmd + 1) * sizeof(char *));
		while (i <= (*data)->nb_cmd - 1)
		{
			(*data)->cmds[i] = ft_strdup(argv[i + 3]);
			i++;
		}
		(*data)->cmds[i] = NULL;
	}
}

void	open_pipe(t_data **data)
{
	int	i;

	i = 0;
	(*data)->pipe_fd = malloc(((*data)->nb_cmd - 1) * sizeof(int *));
	while (i < (*data)->nb_cmd -1)
	{
		(*data)->pipe_fd[i] = malloc(2 * sizeof(int));
		pipe((*data)->pipe_fd[i]);
		i++;
	}
}

void	close_parent_pipes(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->nb_cmd - 1)
	{
		close(data->pipe_fd[j][0]);
		close(data->pipe_fd[j][1]);
		j++;
	}
}

void	wait_children(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd)
	{
		waitpid(data->children[i], NULL, 0);
		i++;
	}
}

void	close_pipe(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->nb_cmd - 1)
	{
		close(data->pipe_fd[j][0]);
		close(data->pipe_fd[j][1]);
		j++;
	}
}
