/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 09:42:24 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 09:22:27 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_point *pts, double zoom, int off_x, int off_y)
{
	int	tmp;

	tmp = pts->x;
	pts->x = ((tmp - pts->y) * cos((5 * M_PI / 6))) * zoom;
	pts->y = ((tmp + pts->y) * sin((M_PI / 6)) - pts->z) * zoom;
	pts->x += off_x;
	pts->y += off_y;
}

void	ft_print_map(t_mlx *img, t_point *pts)
{
	while (pts)
	{
		ft_isometric(pts, img->p->zoom, img->p->off_x, img->p->off_y);
		pts = pts->next;
	}
}

void	ft_near_flat(t_mlx *img, t_point *start, t_point *end, t_line *l)
{
	t_point	*tmp;

	tmp = ft_create_pts(start->x, start->y, start->z, start->color);
	if (l->dy < 0)
		l->i_y = -1;
	if (l->dx < 0)
		l->i_x = -1;
	l->choice = (2 * abs(l->dy)) - abs(l->dx);
	while (tmp->x != end->x)
	{
		if (l->choice <= 0)
			l->choice = l->choice + 2 * abs(l->dy);
		else
		{
			l->choice = l->choice + 2 * (abs(l->dy) - abs(l->dx));
			tmp->y += l->i_y;
		}
		tmp->x += l->i_x;
		if (ft_is_in_map(tmp, img->p->width, img->p->height) == 1)
			ft_put_pixel(img, tmp->x, tmp->y, ft_new_col(start, end, tmp));
	}
	free(tmp);
}

void	ft_near_column(t_mlx *img, t_point *start, t_point *end, t_line *l)
{
	t_point	*tmp;

	tmp = ft_create_pts(start->x, start->y, start->z, start->color);
	l->choice = (2 * abs(l->dx)) - abs(l->dy);
	if (l->dx < 0)
		l->i_x = -1;
	if (l->dy < 0)
		l->i_y = -1;
	while (tmp->y != end->y)
	{
		if (l->choice <= 0)
			l->choice = l->choice + 2 * abs(l->dx);
		else
		{
			l->choice = l->choice + 2 * (abs(l->dx) - abs(l->dy));
			tmp->x += l->i_x;
		}
		tmp->y += l->i_y;
		if (ft_is_in_map(tmp, img->p->width, img->p->height) == 1)
			ft_put_pixel(img, tmp->x, tmp->y, ft_new_col(start, end, tmp));
	}
	free(tmp);
}

void	ft_print_line(t_mlx *img, t_point *start, t_point *end)
{
	t_line	line;

	line.dx = (end->x - start->x);
	line.dy = (end->y - start->y);
	line.i_x = 1;
	line.i_y = 1;
	if (abs(line.dx) >= abs(line.dy))
		ft_near_flat(img, start, end, &line);
	else
		ft_near_column(img, start, end, &line);
}
