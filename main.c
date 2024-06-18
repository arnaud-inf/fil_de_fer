/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:31:11 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 14:48:44 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_print_pts(t_point *p)
{
	while (p)
	{
		printf("%d,%d\n", p->x, p->y);
		p = p->next;
	}
}

int	ft_close(t_mlx *data)
{
	if (data)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_display(data->mlx_ptr);
		ft_free_all(data);
		exit(0);
	}
	return (0);
}

int	ft_mouse(int button, int x, int y, t_mlx *data)
{
	if (!x || !y)
		return (1);
	if (button == 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		data->p->zoom += 0.5;
		ft_apply_o(&data->p->pt, data->p->o);
		ft_print_map(data, data->p->pt);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	if (button == 5)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		ft_img_init(data, data->p->width, data->p->height);
		if (data->p->zoom > 0)
			data->p->zoom -= 0.5;
		ft_apply_o(&data->p->pt, data->p->o);
		ft_print_map(data, data->p->pt);
		ft_drawline(data, data->p->pt);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img_ptr, 0, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	ft_errors(argc, argv[1]);
	ft_init(&data, "HAHAHA", argv[1]);
	ft_print_map(&data, data.p->pt);
	ft_drawline(&data, data.p->pt);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img_ptr, 0, 0);
	mlx_mouse_hook(data.mlx_window, ft_mouse, &data);
	mlx_key_hook(data.mlx_window, ft_exec_input, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
