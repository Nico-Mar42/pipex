/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_in_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:40:10 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/27 16:05:24 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_set(char c, const char *set)
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

int	ft_not_in_set(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	if (!s || !set)
		return (0);
	while (s_set(s[i], set) == 1 && s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0' || s[i] == '\n')
		return (1);
	else
		return (0);
}
