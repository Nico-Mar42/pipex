/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:10:07 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strldup(const char *src, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = ft_calloc(len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
