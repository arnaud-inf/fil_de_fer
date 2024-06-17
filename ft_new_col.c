/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:31:50 by aelison           #+#    #+#             */
/*   Updated: 2024/06/10 09:35:48 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_fract(t_point *s, t_point *end, t_point *inc)
{
	int		dx;
	int		dy;
	float	res;

	dx = end->x - s->x;
	dy = end->y - s->y;
	if (abs(dx) > abs(dy))
	{
		if (s->x != end->x)
			res = (float)(inc->x - s->x) / (end->x - s->x);
		else
			res = 0;
	}
	else
	{
		if (s->y != end->y)
			res = (float)(inc->y - s->y) / (end->y - s->y);
		else
			res = 0;
	}
	return (res);
}

int	ft_new_col(t_point *s, t_point *end, t_point *inc)
{
	int		r;
	int		g;
	int		b;
	float	fract;

	fract = ft_fract(s, end, inc);
	r = get_r(s->color) + (get_r(end->color) - get_r(s->color)) * fract;
	g = get_g(s->color) + (get_g(end->color) - get_g(s->color)) * fract;
	b = get_b(s->color) + (get_b(end->color) - get_b(s->color)) * fract;
	return (create_trgb(get_t(s->color), r, g, b));
}
