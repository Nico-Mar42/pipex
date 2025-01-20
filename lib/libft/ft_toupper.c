/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:34:36 by nicolmar          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:42 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	int	rep;

	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		rep = c - 32;
	else
		rep = c;
	return (rep);
}
