/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:56:41 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/13 16:03:38 by dvauthey         ###   ########.fr       */
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
static int	color_line(int keycode, t_vars *vars)
{
	if (keycode == 97)
	{
			for(int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				my_mlx_pixel_put((&vars->img), 100 + i, 100 + j, 0x00CC99FF);
			}
		}
	}
	ft_printf("keycode : %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "bruh");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img).bits_per_pixel, &(vars.img).line_length,
		&(vars.img).endian);
	
//	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_closing, &vars);
	mlx_key_hook(vars.win, &color_line, &vars);
	//mlx_mouse_hook(vars.win, &mouse_hold, &vars);
	mlx_loop(vars.mlx);
	return (0);
}