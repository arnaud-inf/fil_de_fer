/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:43 by aelison           #+#    #+#             */
/*   Updated: 2024/06/11 13:55:42 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_in_map(t_point *pts, int width, int height)
{
	if ((pts->x >= 0 && pts->x <= width) && (pts->y >= 0 && pts->y <= height))
		return (1);
	return (0);
}

void	ft_drawline(t_mlx *img, t_point *pts)
{
	t_point	*tmp;

	while (pts->next)
	{
		tmp = pts->next;
		if (pts->x < tmp->x)
			ft_print_line(img, pts, tmp);
		if (pts->bottom != NULL)
			ft_print_line(img, pts, pts->bottom);
		pts = pts->next;
		tmp = tmp->next;
	}
}
