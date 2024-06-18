/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:14:15 by aelison           #+#    #+#             */
/*   Updated: 2024/06/18 09:44:28 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_line
{
	int	i_x;
	int	i_y;
	int	dx;
	int	dy;
	int	choice;
}	t_line;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
	struct s_point	*bottom;
	struct s_point	*last;
}	t_point;

typedef struct s_positions
{
	int		width;
	int		height;
	double	zoom;
	int		off_x;
	int		off_y;
	int		total_ligne;
	int		total_column;
	int		z_max;
	t_point	*o;
	t_point	*pt;
}	t_positions;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_window;
	void		*img_ptr;
	char		*img_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_positions	*p;
}	t_mlx;

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		ft_new_col(t_point *s, t_point *end, t_point *inc);

int		ft_exec_input(int keycode, t_mlx *data);
int		ft_elem_exist(char *str, char elem);
int		ft_atoi_base(char *str, int base);
int		ft_is_in_map(t_point *pts, int width, int height);
int		ft_all_pts(t_positions *p, char **str, int y);
int		ft_init_aux(t_positions *pts, char *line, int y);

void	ft_errors(int argc, char *argv);
void	ft_put_pixel(t_mlx *img, int x, int y, int color);
void	ft_print_line(t_mlx *img, t_point *start, t_point *end);
void	ft_print_map(t_mlx *img, t_point *pts);
void	ft_free_all(t_mlx *data);
void	ft_drawline(t_mlx *img, t_point *pts);
void	ft_center_pts(t_positions *pts);

void	ft_img_init(t_mlx *data, int x, int y);
void	ft_init(t_mlx *data, char *title, char *str);
void	ft_init_zoom(t_mlx *data);
void	ft_add_pts(t_point **pts, t_point *elem);
void	ft_free_pts(t_point *pts);
void	ft_free_positions(t_positions *p);

t_point	*ft_create_pts(int x, int y, int z, int color);

void	ft_apply_o(t_point **pt, t_point *o);
void	ft_change_x(t_point **pt, int inc_x);
void	ft_change_y(t_point **pt, int inc_y);
void	ft_change_z(t_point **pt, int inc_z);
void	ft_print_pts(t_point *p);
#endif
