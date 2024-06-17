/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:54:21 by aelison           #+#    #+#             */
/*   Updated: 2024/06/11 11:54:50 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_positions(t_positions *p)
{
	ft_free_pts(p->o);
	ft_free_pts(p->pt);
	free(p);
}

t_point	*ft_create_pts(int x, int y, int z, int color)
{
	t_point	*result;

	result = malloc(sizeof(t_point));
	if (!result)
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	result->color = color;
	result->next = NULL;
	result->bottom = NULL;
	result->last = NULL;
	return (result);
}

void	ft_add_pts(t_point **pts, t_point *elem)
{
	if (*pts == NULL)
	{
		*pts = elem;
		elem->next = NULL;
		(*pts)->last = elem;
	}
	else
	{
		(*pts)->last->next = elem;
		(*pts)->last = elem;
		if (elem->x == 0 && elem->y == 1)
			(*pts)->bottom = elem;
	}
}

int	ft_atoi_base(char *str, int base)
{
	int		i;
	int		result;
	int		letter;

	i = 0;
	result = 0;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	else if (str[i] == '0' && str[i + 1] == 'X')
		i += 2;
	while (str[i] != '\0' && str[i] != '\n')
	{
		result = result * base;
		letter = ft_tolower(str[i]);
		if (letter >= 'a' && letter <= 'f')
			result = result + (letter - 'a' + 10);
		else if (letter >= '0' && letter <= '9')
			result = result + (letter - '0');
		i++;
	}
	return (result);
}
