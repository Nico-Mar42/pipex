/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:38:52 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rep;
	size_t	s_len;
	size_t	rep_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	rep_len = s_len - start;
	if (rep_len > len)
		rep_len = len;
	rep = malloc(rep_len + 1 * 1);
	if (rep == NULL)
		return (NULL);
	ft_strlcpy(rep, s + start, rep_len + 1);
	rep[rep_len] = '\0';
	return (rep);
}
