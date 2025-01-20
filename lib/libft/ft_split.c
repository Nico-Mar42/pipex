/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:34 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countword(size_t len, char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	free_all(char **dest, int k)
{
	while (k > 0)
		free(dest[--k]);
	free(dest);
}

char	**split1(char **dest, size_t len, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	while (i < len)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			dest[k] = ft_strldup(&s[j], i - j);
			if (dest[k] == NULL)
				return (free_all(dest, k), NULL);
			k++;
		}
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = ft_calloc(countword(len, s, c) + 1, sizeof(char *));
	if (!dest)
		return (NULL);
	if (!split1(dest, len, s, c))
		return (NULL);
	return (dest);
}
