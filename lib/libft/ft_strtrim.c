/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:02:29 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && s_set(s1[i], set))
		i++;
	while (j > i && s_set(s1[j - 1], set))
		j--;
	return (ft_substr(s1, i, j - i));
}
