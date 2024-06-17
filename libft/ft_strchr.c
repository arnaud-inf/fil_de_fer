/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:21:17 by aelison           #+#    #+#             */
/*   Updated: 2024/03/05 12:20:05 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;
	char	*addr;

	i = 0;
	len_s = ft_strlen(s);
	addr = (char *)s;
	if ((char)c == '\0')
		return (addr + len_s);
	while (addr[i] != '\0')
	{
		if (addr[i] == (char)c)
			return (addr + i);
		i = i + 1;
	}
	return (NULL);
}
