/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:04 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 18:06:24 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/src/libft.h"

typedef struct s_dataimg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_dataimg;	

typedef struct	s_map
{
	int		**map_tab;
	double	**matrix;
	int		*map_colours;
	int		x_len;
	int		y_len;
	int		len_matrix;
	int 	delay[2];
	int		i_c[2];
	int		dxy[2];
}			t_map;

typedef struct	s_win_size
{
	int	x_len;
	int	y_height;
	int	x_middle;
	int	y_middle;
}		t_win_size;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_dataimg	img;
	t_map		map;
	t_win_size	win_sizes;
}				t_vars;

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}			t_coord;

typedef struct	s_colour
{
	int	r;
	int	g;
	int	b;
	int	c;
}		t_colour;

void	error_exit_perror(int fd, t_map map, char *message);
void	error_exit_write(int fd, t_map map, char *message);
void	freesplit(char **s);
void	freeatoi(int **tab, int y);

int		size_x(char **map_read);
int		highest_elt(t_vars *vars);
int		lowest_elt(t_vars *vars);
int		str_to_hexaint(char *str);

void	my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);

t_coord	matrix_rotation(int x, int y, int z);

int		opening_file(char *file);
int		*getting_colours(t_map *map, char **map_read);
void	creating_map(t_map *map);
void	drawing_map(t_vars *vars);
int		interpolation(t_vars *vars, int *x, int *y);
void	edges(t_vars *vars);
void	ft_fdf(int fd, char *file_name);

#endif 