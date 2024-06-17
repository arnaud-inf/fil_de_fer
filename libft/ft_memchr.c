/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:14:45 by aelison           #+#    #+#             */
/*   Updated: 2024/03/05 12:19:23 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*result;
	char	find;

	i = 0;
	find = (char)c;
	result = (char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (result[i] == find)
			return ((void *)result + i);
		i = i + 1;
	}
	return (NULL);
}
