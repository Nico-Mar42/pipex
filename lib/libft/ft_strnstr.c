/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:15:13 by nicolmar          #+#    #+#             */
/*   Updated: 2024/10/21 12:16:06 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <unistd.h>

char	*ft_strnstr(const char *find, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*search)
		return ((char *)find);
	while (i < len && find[i] > 0)
	{
		j = 0;
		while (search[j] && find[i + j]
			&& i + j < len && find[i + j] == search[j])
			j++;
		if (search[j] == 0)
			return ((char *)&find[i]);
		i++;
	}
	return (NULL);
}
