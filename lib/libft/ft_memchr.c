/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:29:50 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/21 11:38:11 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memchr(const void *mB, int sC, size_t size)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)mB;
	i = 0;
	while (i != size)
	{
		if (ptr[i] == (unsigned char)sC)
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
