/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:04 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/29 17:58:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	char	**map_read;
	int		**map_tab;
	int		x_len;
	int		y_len;
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
typedef struct	s_delay_direction
{
	double	delay[2];
	double	direction[3];
}			t_delay_direction;

void	error_exit_perror(int fd, t_map map, char *message);
void	error_exit_write(int fd, t_map map, char *message);
void	freesplit(char **s);
void	freeatoi(int **tab, int y);
int		size_x(t_map map);
void	my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
t_coord	matrix_rotation(t_coord co);
int		opening_file(char *file);
void	creating_map(t_map map);
void	edges_line(t_vars vars, t_coord a, t_coord b, int factor);
void	edges_column(t_vars vars, t_coord a, t_coord b, int factor);
void	drawing_map(t_vars vars);
void	ft_fdf(int fd, char *file_name);

#endif 