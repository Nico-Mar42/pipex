/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:48:35 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/24 14:07:11 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char *here_doc(char *limiter)
{
	int		tmp;
	char	*nl;

	tmp = open(".tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("pipe Heredoc> ", 1);
	limiter = ft_strjoin(limiter, "\n");
	nl = get_next_line(0);
	while (ft_strncmp(limiter, nl, ft_strlen(limiter)) != 0)
	{
		ft_putstr_fd("pipe Heredoc> ", 1);
		ft_putstr_fd(nl, tmp);
		free(nl);
		nl = get_next_line(0);	
	}
	free(nl);
	close(tmp);
	free(limiter);
	return (".tmp.txt");
}