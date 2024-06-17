/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:31:11 by aelison           #+#    #+#             */
/*   Updated: 2024/06/14 11:54:09 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(int argc, char **argv)
{
	t_mlx	data;

	ft_errors(argc, argv[1]);
	ft_init(&data, "HAHAHA", argv[1]);
	ft_print_map(&data, data.p->pt);
	ft_drawline(&data, data.p->pt);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img_ptr, 0, 0);
	mlx_key_hook(data.mlx_window, ft_exec_input, &data);
	mlx_hook(data.mlx_window, 17, 1L << 17, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
