/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:57:29 by aelison           #+#    #+#             */
/*   Updated: 2024/06/11 08:11:45 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	return (i);
}

char	*ft_strdup_gnl(char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen_gnl((const char *)s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strchr_gnl(char *s, int c)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen_gnl((const char *)s);
	while (i < len_s)
	{
		if (s[i] == (char)c)
			return ((int)i);
		i = i + 1;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		k;

	i = 0;
	k = 0;
	result = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		result[i + k] = s2[k];
		k++;
	}
	result[i + k] = '\0';
	free(s1);
	return (result);
}

char	*ft_substr_gnl(char *s, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while ((i < len) && s)
	{
		result[i] = s[start];
		start = start + 1;
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}
