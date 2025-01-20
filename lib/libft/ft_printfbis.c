/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:31:41 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

long	printpoint(char c, unsigned long d)
{
	char	*hexa;
	int		count;

	if (d == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count = 0;
	hexa = "0123456789abcdef";
	if (d >= 16)
		count += printpoint(c, d / 16);
	count++;
	ft_putchar(hexa[d % 16]);
	return (count);
}

int	printhexa(char c, unsigned int d)
{
	char	*lower;
	char	*upper;
	char	*hexa;
	int		count;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	count = 0;
	if (c == 'X')
		hexa = upper;
	else
		hexa = lower;
	if (d >= 16)
		count += printhexa(c, d / 16);
	count++;
	ft_putchar(hexa[d % 16]);
	return (count);
}

int	printchar(char c)
{
	ft_putchar(c);
	return (1);
}

int	printusint(unsigned int d)
{
	char	*rslt;
	int		len;

	rslt = ft_usitoa((unsigned int)d);
	len = ft_strlen(rslt);
	ft_putstr(rslt);
	free(rslt);
	return (len);
}

int	printint(int d)
{
	char	*rslt;
	int		len;

	rslt = ft_itoa(d);
	len = ft_strlen(rslt);
	ft_putstr(rslt);
	free(rslt);
	return (len);
}
