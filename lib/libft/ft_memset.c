/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:34 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/16 10:59:06 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *str, int v, size_t n )
{
	char	*s;

	if (str == NULL)
		return (NULL);
	s = str;
	while (n != 0)
	{
		*s = v;
		s++;
		n--;
	}
	return (str);
}
