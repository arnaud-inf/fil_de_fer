/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:53:21 by aelison           #+#    #+#             */
/*   Updated: 2024/02/24 08:26:17 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dest;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size > len_dest)
	{
		while (src[i] != '\0' && size > len_dest + 1)
		{
			dest[len_dest + i] = src[i];
			i = i + 1;
			size = size - 1;
		}
		dest[len_dest + i] = '\0';
	}
	else
		return (size + len_src);
	return (len_src + len_dest);
}
