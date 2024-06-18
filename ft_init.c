/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:29:23 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 08:14:11 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_pts(t_positions *pts, char *str)
{
	int		stop;
	int		fd;
	char	*line;
	int		y;

	y = 0;
	line = "\0";
	fd = open(str, O_RDONLY);
	stop = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (ft_init_aux(pts, line, y) == 0)
			stop = 0;
		free(line);
		y++;
	}
	if (stop == 0)
	{
		ft_free_positions(pts);
		close(fd);
		exit(1);
	}
	pts->total_ligne = y;
	close(fd);
}

void	ft_init_offset(t_positions *p)
{
	p->off_x = p->width / 2;
	p->off_y = p->height / 2;
}

void	ft_win_init(t_mlx *data, int x, int y, char *title)
{
	data->mlx_window = mlx_new_window(data->mlx_ptr, x, y, title);
	if (data->mlx_window == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		ft_free_all(data);
		exit(1);
	}
}

void	ft_img_init(t_mlx *data, int x, int y)
{
	t_mlx	tmp;

	tmp = *data;
	tmp.img_ptr = mlx_new_image(tmp.mlx_ptr, x, y);
	tmp.img_addr = mlx_get_data_addr(tmp.img_ptr,
			&(tmp).bits_per_pixel,
			&(tmp).size_line,
			&(tmp).endian);
	*data = tmp;
}

void	ft_init(t_mlx *data, char *title, char *str)
{
	data->p = malloc(sizeof(t_positions));
	if (data->p == NULL)
		exit(1);
	data->p->o = NULL;
	data->p->pt = NULL;
	data->p->z_max = 0;
	data->p->total_column = 0;
	ft_init_pts(data->p, str);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	mlx_get_screen_size(data->mlx_ptr, &data->p->width, &data->p->height);
	ft_win_init(data, data->p->width, data->p->height, title);
	ft_img_init(data, data->p->width, data->p->height);
	ft_center_pts(data->p);
	ft_init_zoom(data);
	ft_init_offset(data->p);
}
