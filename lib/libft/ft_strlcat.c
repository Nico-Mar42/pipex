/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:26:43 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;
	size_t	srclen;

	dstlen = 0;
	srclen = ft_strlen(src);
	while (dst[dstlen] != '\0' && dstlen < size)
		dstlen++;
	if (size == 0 || dstlen >= size)
		return (srclen + size);
	i = dstlen;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
