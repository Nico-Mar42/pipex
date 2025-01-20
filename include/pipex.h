/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:52:21 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/20 17:03:22 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int			pipe_fd[2];
	int			fd_in;
	int			fd_out;
	pid_t		child1;
	pid_t		child2;
}				t_data;

typedef struct s_cmd
{
	char		**path;
	char		**cmd_arg;
}			t_cmd;


#endif