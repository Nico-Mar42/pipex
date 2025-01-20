/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:22 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/21 20:49:44 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp( const char *first, const char *second, size_t length )
{
	size_t	i;

	i = 0;
	while (i != length)
	{
		if ((unsigned char)first[i] != (unsigned char)second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
		if (first[i] == 0 && second[i] == 0)
			return (0);
	}
	return (0);
}
