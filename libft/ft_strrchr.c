/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:19:27 by aelison           #+#    #+#             */
/*   Updated: 2024/03/01 08:55:07 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;
	char			*result;

	i = 0;
	ptr = (char *)s;
	result = NULL;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			result = ptr + i;
		i = i + 1;
	}
	if ((char)c == '\0')
	{
		result = ptr + i;
	}
	return (result);
}
