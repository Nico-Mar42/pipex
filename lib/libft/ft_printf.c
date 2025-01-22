/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draask <draask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:00:42 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/21 12:47:08 by draask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	printstr(char *str)
{
	int	len;

	if (str == NULL)
	{
		ft_putstr("(null)");
		len = 6;
		return (len);
	}
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int	printtype(char c, int count, va_list ap)
{
	unsigned long	p;

	if (c == 'c')
		count += printchar(va_arg(ap, int));
	if (c == 's')
		count += printstr(va_arg(ap, char *));
	if (c == 'd' || c == 'i')
		count += printint(va_arg(ap, int));
	if (c == 'u')
		count += printusint(va_arg(ap, unsigned int));
	if (c == '%')
		count += printchar('%');
	if (c == 'x')
		count += printhexa(c, va_arg(ap, unsigned int));
	if (c == 'X')
		count += printhexa(c, va_arg(ap, unsigned int));
	if (c == 'p')
	{
		p = va_arg(ap, unsigned long);
		if (p != 0)
			count += printstr("0x");
		count += printpoint(c, p);
	}
	return (count);
}

int	ft_printf(const	char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != 0)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			count++;
			format++;
		}
		else
		{
			count = printtype(*++format, count, ap);
			format++;
		}
	}
	return (count);
}

//int	main(void)
//{
//	char	*str = "terte";
//	long 	len = LONG_MIN;
//	printf("taille total %d\n", ft_printf("test putchar = %c\n", 'G'));
//	printf("taille total %d\n", ft_printf("test putstr = %s\n", "quand"));
//	printf("taille total %d\n", ft_printf("test putdec = %d\n", -888));
//	printf("taille total %d\n", ft_printf("test putint = %i\n", 888));
//	printf("taille total %d\n", ft_printf("test put-usint = %u\n", -8));
//	printf("taille total %d\n", ft_printf("test put-percent = %%\n"));
//	printf("taille total %d\n", ft_printf("test put-hexalower = %x\n", 89));
//	printf("taille total %d\n", ft_printf("test put-hexaupper = %x\n", 89));
//	printf("taille total %d\n", ft_printf("test put-void = %p\n", &len));
//	printf("taille total %d\n", printf("test put-void = %p\n", &len));
//	return (0);
//}
