/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:57:42 by draask            #+#    #+#             */
/*   Updated: 2025/01/27 09:40:46 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntchar(unsigned int n)
{
	unsigned int	mod;
	int				rep;

	mod = n;
	rep = 0;
	while (mod >= 10)
	{
		mod = mod / 10;
		rep++;
	}
	return (rep);
}

char	*ft_usitoa(unsigned int n)
{
	int					len;
	unsigned int		temp;
	char				*rep;

	len = cntchar(n);
	rep = ft_calloc(len + 2, 1);
	if (!rep)
		return (NULL);
	temp = n;
	while (len >= 0)
	{
		rep[len] = (temp % 10) + 48;
		len--;
		temp = temp / 10;
	}
	return (rep);
}
