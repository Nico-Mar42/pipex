/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:08:30 by nicolmar          #+#    #+#             */
/*   Updated: 2025/01/14 17:08:40 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdint.h>
#include <unistd.h>
#include <limits.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*data;
	size_t	totalsize;

	if (elementCount == 0 || elementSize == 0)
		return (NULL);
	if (elementCount > SIZE_MAX / elementSize)
		return (NULL);
	totalsize = elementCount * elementSize;
	data = malloc(totalsize);
	if (data == NULL)
		return (NULL);
	ft_bzero(data, totalsize);
	return (data);
}
