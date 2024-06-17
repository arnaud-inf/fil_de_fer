/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:09:18 by aelison           #+#    #+#             */
/*   Updated: 2024/06/12 14:04:16 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_zoom(t_mlx *data)
{
	int		border;
	int		max;
	int		zoom;

	border = data->p->height - 500;
	if (data->p->total_column > data->p->total_ligne)
		max = data->p->total_column;
	else
		max = data->p->total_ligne;
	zoom = (border / (max + data->p->z_max));
	if (zoom == 0)
		zoom += 1;
	data->p->zoom = zoom;
}

void	ft_free_pts(t_point *pts)
{
	t_point	*tmp;

	while (pts)
	{
		tmp = pts->next;
		free(pts);
		pts = tmp;
	}
}

int	ft_init_aux(t_positions *pts, char *line, int y)
{
	int		res;
	char	**stock;

	res = 1;
	if (line != NULL)
	{
		stock = ft_split(line, ' ');
		if (ft_all_pts(pts, stock, y) == 0)
			res = 0;
		free_all(stock);
	}
	return (res);
}

static void	ft_all_pts_aux(t_positions *p, int i, int y, char *str)
{
	int		color;
	int		pos;
	int		z;
	char	*tmp;

	pos = ft_elem_exist(str, ',');
	if (pos == -1)
	{
		z = ft_atoi(str);
		color = 0xffffffff;
		ft_add_pts(&(p->pt), ft_create_pts(i, y, z, color));
		ft_add_pts(&(p->o), ft_create_pts(i, y, z, color));
	}
	else
	{
		tmp = ft_substr(str, 0, pos);
		z = ft_atoi(tmp);
		free(tmp);
		color = ft_atoi_base(str + pos + 1, 16);
		ft_add_pts(&(p->pt), ft_create_pts(i, y, z, color));
		ft_add_pts(&(p->o), ft_create_pts(i, y, z, color));
	}
	if (p->z_max < z)
		p->z_max = z;
}

int	ft_all_pts(t_positions *p, char **str, int y)
{
	int		i;

	i = 0;
	while (str[i] != NULL && str[i][0] != '\n')
	{
		ft_all_pts_aux(p, i, y, str[i]);
		i++;
	}
	if (y == 0)
		p->total_column = i;
	else if (i != p->total_column)
	{
		ft_putstr_fd("Error : wrong line lenght\n", 2);
		return (0);
	}
	return (1);
}
