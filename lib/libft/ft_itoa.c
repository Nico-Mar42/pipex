/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:57:42 by draask            #+#    #+#             */
/*   Updated: 2025/01/14 17:09:48 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	cntchar(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*intmin(void)
{
	char	*rep;

	rep = ft_calloc(12, sizeof(char));
	if (!rep)
		return (NULL);
	ft_strlcpy(rep, "-2147483648", 12);
	return (rep);
}

char	*ft_itoa(long n)
{
	int		len;
	int		i;
	char	*rep;

	if (n == INT_MIN)
		return (intmin());
	len = cntchar(n);
	rep = ft_calloc(len + 1, sizeof(char));
	if (!rep)
		return (NULL);
	if (n < 0)
	{
		rep[0] = '-';
		n = -n;
	}
	else if (n == 0)
		rep[0] = '0';
	i = len - 1;
	while (n != 0)
	{
		rep[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (rep);
}
