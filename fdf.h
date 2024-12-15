/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:04 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/15 17:41:01 by dvauthey         ###   ########.fr       */
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

void	error_exit(int fd, char **map, char *message);
int		opening_file(char *file);
void	my_mlx_pixel_put(t_dataimg *data, int x, int y, int color);
void	ft_fdf(int fd, char *file_name);

#endif 