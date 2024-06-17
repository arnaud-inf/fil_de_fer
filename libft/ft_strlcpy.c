/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:49:34 by aelison           #+#    #+#             */
/*   Updated: 2024/02/23 10:36:52 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while ((i < size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i = i + 1;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}
