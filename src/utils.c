/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:20:02 by draask            #+#    #+#             */
/*   Updated: 2025/01/22 16:34:59 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void error(int error, char *cmd)
{
	if (error == 1)
		perror("malloc failed");
	else if (error == 2)
		perror("ft_split failed");
	else if (error == 3)
	{
		ft_printf("Command not found: %s\n", cmd);
	}
	else if (error == 4)
	{
		perror("fork failed");
	}
	else if (error == 5)
	{
		ft_printf("execve failed: %s\n", cmd);
	}
	exit(1);
}

void	parse_cmd(t_data **data, int argc, char **argv)
{
	int	i;

	i = 0;
	(*data)->nb_cmd = argc - 3;
	(*data)->cmds = malloc(((*data)->nb_cmd + 1) * sizeof(char *));
	if ((*data)->cmds == NULL)
		error(1, NULL);
	while (i <= (*data)->nb_cmd - 1)
	{
		(*data)->cmds[i] = ft_strdup(argv[i + 2]);
		i++;
	}
	(*data)->cmds[i] = NULL;

}

void	open_pipe(t_data **data)
{
	int	i;

	i = 0;
	(*data)->pipe_fd = malloc(((*data)->nb_cmd - 1) * sizeof(int *));
	//error gestion
	while (i < (*data)->nb_cmd -1)
	{
		(*data)->pipe_fd[i] = malloc(2 * sizeof(int));
		pipe((*data)->pipe_fd[i]);
		//error gestion
		i++;
	}
}

void	close_parent_pipes(t_data *data)
{
	int j = 0;
	while (j < data->nb_cmd - 1)
	{
		close(data->pipe_fd[j][0]);
		close(data->pipe_fd[j][1]);
		j++;
	}
}

void	wait_children(t_data *data)
{
	int i = 0;
	while (i < data->nb_cmd)
	{
		waitpid(data->children[i], NULL, 0);
		i++;
	}
}

