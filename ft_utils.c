/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:34:16 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 14:44:18 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point	*ft_find_center_pts(t_positions *pts)
{
	t_point	*res;

	res = ft_create_pts(0, 0, 0, 0xFFFFFF);
	res->x = ((pts->total_ligne -1) / 2);
	res->y = ((pts->total_ligne -1) / 2);
	return (res);
}

void	ft_center_pts(t_positions *pts)
{
	t_point	*o;
	t_point	*pt;
	t_point	*change;
	t_point	*bottom;

	o = pts->o;
	pt = pts->pt;
	change = ft_find_center_pts(pts);
	bottom = pt->bottom;
	while (pt)
	{
		o->x = (change->x - o->x);
		o->y = (change->y - o->y) * (-1);
		pt->x = (change->x - pt->x);
		pt->y = (change->y - pt->y) * (-1);
		if (bottom != NULL)
		{
			pt->bottom = bottom;
			bottom = bottom->next;
		}
		o = o->next;
		pt = pt->next;
	}
	free(change);
}

int	ft_exec_input(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		ft_free_all(data);
		exit(0);
	}
	if (keycode == 65361) //gauche
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		ft_change_x(&data->p->pt, -5);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	if (keycode == 65363) //droite
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		ft_change_x(&data->p->pt, 5);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	if (keycode == 65362) //haut
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		ft_change_y(&data->p->pt, -5);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	if (keycode == 65364) //bas
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		ft_change_y(&data->p->pt, 5);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	return (0);
}

void	ft_put_pixel(t_mlx *img, int x, int y, int color)
{
	char	*str;

	str = img->img_addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)str = color;
}

void	ft_free_all(t_mlx *data)
{
	ft_free_pts(data->p->o);
	ft_free_pts(data->p->pt);
	free(data->p);
	free(data->mlx_ptr);
}
