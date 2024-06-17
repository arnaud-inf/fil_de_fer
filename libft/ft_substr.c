/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:01:11 by aelison           #+#    #+#             */
/*   Updated: 2024/03/02 08:21:16 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*substr_aux(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while ((i < len) && s[i] != '\0')
	{
		result[i] = s[start];
		start = start + 1;
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen((const char *)s);
	i = 0;
	if (len > len_s - start)
		len = len_s - start;
	if (start >= len_s)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		result[i] = '\0';
		return (result);
	}
	else
		result = substr_aux(s, start, len);
	return (result);
}
