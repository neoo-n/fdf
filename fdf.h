/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:04 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/18 16:06:18 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_dataimg	img;
}				t_vars;

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



void	error_exit_perror(int fd, t_map map, char *message);
void	error_exit_write(int fd, t_map map, char *message);
void	freesplit(char **s);
void	freeatoi(int **tab, int y);
int		size_x(t_map map);
void	my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void	edges_h(t_vars vars, int x_start, int x_end, int y);
void	edges_v(t_vars vars, int x, int y_start, int y_end);
int		opening_file(char *file);
void	creating_map_2d(t_map map);
void	ft_fdf(int fd, char *file_name);

#endif 