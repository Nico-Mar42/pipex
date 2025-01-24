/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:52:21 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/24 16:07:50 by nicolmar         ###   ########.fr       */
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
	int			nb_cmd;
	int			**pipe_fd;
	char		**cmds;
	char		*infile;
	char		*outfile;
	int			here_doc;
	pid_t		*children;
}				t_data;

typedef struct s_child
{
	char	**args;
	char	*path;
}			t_child;

char	*get_path(char *cmd, char **envp);
void	error(int error, t_data *data, t_child *child);
void	parse_cmd(t_data **data, int argc, char **argv);
void	open_pipe(t_data **data);
void	free_data(t_data *data);
void	close_parent_pipes(t_data *data);
void	wait_children(t_data *data);
void	free_str_array(char **array);
void	close_pipe(t_data *data);
void	first_child(t_data *data, char **envp, int i);
void	last_child(t_data *data, char **envp, int i);
void	int_child(t_data *data, char **envp, int i);
char	*here_doc(char *limiter);

#endif