/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:25:15 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/16 10:58:24 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_bzero(void *str, size_t n )
{
	char	*s;

	if (str == NULL)
		return (NULL);
	s = str;
	while (n != 0)
	{
		*s = 0;
		s++;
		n--;
	}
	return (str);
}
