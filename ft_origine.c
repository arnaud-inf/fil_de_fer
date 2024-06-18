/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_origine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:17:13 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 14:42:56 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_apply_o(t_point **pt, t_point *o)
{
	t_point	*tmp;

	tmp = *pt;
	while (tmp)
	{
		tmp->x = o->x;
		tmp->y = o->y;
		tmp->z = o->z;
		o = o->next;
		tmp = tmp->next;
	}
}

void	ft_change_x(t_point **pt, int inc_x)
{
	t_point	*tmp;

	tmp = *pt;
	while (tmp)
	{
		tmp->x += inc_x;
		tmp = tmp->next;
	}
}

void	ft_change_y(t_point **pt, int inc_y)
{
	t_point	*tmp;

	tmp = *pt;
	while (tmp)
	{
		tmp->y += inc_y;
		tmp = tmp->next;
	}
}

void	ft_change_z(t_point **pt, int inc_z)
{
	t_point	*tmp;

	tmp = *pt;
	while (tmp)
	{
		tmp->z += inc_z;
		tmp = tmp->next;
	}
}
