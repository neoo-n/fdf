/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:04:49 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/18 15:50:32 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	creating_all(t_vars *vars, t_win_size *win_sizes)
{
	win_sizes->x_len = 1920;
	win_sizes->y_height = 1080;
	win_sizes->x_middle = win_sizes->x_len / 2;
	win_sizes->y_middle = win_sizes->y_height / 2;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, win_sizes->x_len,
		win_sizes->y_height, "42");
	vars->img.img = mlx_new_image(vars->mlx, win_sizes->x_len,
		win_sizes->y_height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bits_per_pixel),
		&(vars->img.line_length), &(vars->img.endian));
}

void	creating_map_2d(t_map map)
{
	t_vars		vars;
	t_win_size	win_sizes;

	creating_all(&vars, &win_sizes);
	ft_printf("map : %i\n", map.map_tab[0][0]);
	edges_h(vars, 100, 150, 100);
	edges_v(vars, 100, 100, 150);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
