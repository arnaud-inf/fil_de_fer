/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:35:19 by aelison           #+#    #+#             */
/*   Updated: 2024/02/22 13:47:40 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				result;
	int				sign;
	unsigned int	p;

	result = 0;
	sign = 1;
	p = 0;
	while ((nptr[p] >= 9 && nptr[p] <= 13) || (nptr[p] == 32))
		p = p + 1;
	if (nptr[p] == '+')
		p = p + 1;
	else if (nptr[p] == '-')
	{
		sign = -1;
		p = p + 1;
	}
	while (ft_isdigit(nptr[p]) != 0)
	{
		result = (10 * result) + (nptr[p] - '0');
		p = p + 1;
	}
	return (result * sign);
}
