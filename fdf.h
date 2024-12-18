/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:04 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/18 11:38:04 by dvauthey         ###   ########.fr       */
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


void	error_exit_perror(int fd, t_map map, char *message);
void	error_exit_write(int fd, t_map map, char *message);
void	freesplit(char **s);
void	freeatoi(int **tab, int y);
int		size_x(t_map map);
void	my_mlx_pixel_put(t_dataimg *data, int x, int y, int color);
int		opening_file(char *file);
void	creating_map_2d(t_map map);
void	ft_fdf(int fd, char *file_name);

#endif 