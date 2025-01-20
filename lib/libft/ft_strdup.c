/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:12:23 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <unistd.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[len] != 0)
		len ++;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
