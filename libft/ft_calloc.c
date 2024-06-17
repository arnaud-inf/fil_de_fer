/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:48:46 by aelison           #+#    #+#             */
/*   Updated: 2024/03/05 16:14:50 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	while (i < nmemb * size)
	{
		result[i] = 0;
		i = i + 1;
	}
	return ((void *)result);
}
