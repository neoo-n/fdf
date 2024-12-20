/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:04:49 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/19 14:33:56 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	mouse_closing(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	closing(int keycode, t_vars *vars)
{
	ft_printf("keycode : %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	creating_all(t_vars *vars, t_win_size *win_sizes)
{
	win_sizes->x_len = 1920;
	win_sizes->y_height = 1080;
	win_sizes->x_middle = win_sizes->x_len / 2;
	win_sizes->y_middle = win_sizes->y_height / 2;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, win_sizes->x_len,
		win_sizes->y_height, "FdF");
	vars->img.img = mlx_new_image(vars->mlx, win_sizes->x_len,
		win_sizes->y_height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bits_per_pixel),
		&(vars->img.line_length), &(vars->img.endian));
}

void	creating_map(t_map map)
{
	t_vars		vars;
	t_win_size	win_sizes;

	creating_all(&vars, &win_sizes);
	drawing_map(vars, map, win_sizes);
	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_closing, &vars);
	mlx_loop(vars.mlx);
}
