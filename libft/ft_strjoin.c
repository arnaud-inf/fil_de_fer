/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:10:45 by aelison           #+#    #+#             */
/*   Updated: 2024/02/23 08:12:27 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*result;
	unsigned int	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i = i + 1;
	}
	i = 0;
	while (i < len_s2)
	{
		result[len_s1] = s2[i];
		len_s1 = len_s1 + 1;
		i = i + 1;
	}
	result[len_s1] = '\0';
	return (result);
}
