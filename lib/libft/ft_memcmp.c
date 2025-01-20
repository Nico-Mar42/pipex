/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:29:50 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/21 11:41:51 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	char		*s1;
	char		*s2;
	size_t		i;

	i = 0;
	s1 = (void *)str1;
	s2 = (void *)str2;
	while (i != size)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
