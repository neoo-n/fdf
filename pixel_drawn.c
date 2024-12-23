/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_drawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/21 19:05:23 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static void	line(t_vars vars, t_win_size win_sizes, int j, int factor)
{
	int		i;
	t_coord	coord1;
	t_coord	coord2;

	i = 0;
	coord1.y = j * factor;
	coord2.y = j * factor;
	while (i < vars.map.x_len - 1)
	{
		coord1.x = i * factor;
		coord2.x = (i + 1) * factor;
		coord1.z = vars.map.map_tab[j][i] * factor;
		coord2.z = vars.map.map_tab[j][i + 1] * factor;
		edges_line(vars, win_sizes, coord1, coord2);
		i++;
	}
}

static void	column(t_vars vars, t_win_size win_sizes, int i, int factor)
{
	int		j;
	t_coord	coord1;
	t_coord	coord2;

	j = 0;
	coord1.x = i * factor;
	coord2.x = i * factor;
	while (j < vars.map.y_len - 1)
	{
		coord1.y = j * factor;
		coord2.y = (j + 1) * factor;
		coord1.z = vars.map.map_tab[j][i] * factor;
		coord2.z = vars.map.map_tab[j + 1][i] * factor;
		edges_column(vars, win_sizes, coord1, coord2);
		j++;
	}
}

void	drawing_map(t_vars vars, t_win_size win_sizes)
{
	int	n;
	int	factor;

	n = 0;
	factor = (win_sizes.x_len * 0.6)/ (vars.map.x_len + 1);
	if ((win_sizes.y_height * 0.6) / (vars.map.y_len + 1) < factor)
		factor = (win_sizes.y_height * 0.6) / (vars.map.y_len + 1);
	if (vars.map.x_len == 1 && vars.map.y_len == 1)
	{
		my_mlx_pixel_put(&(vars.img), win_sizes.x_middle * factor,
			win_sizes.y_middle * factor, 0x00CC99FF);
	}
	while (n < vars.map.y_len)
	{
		line(vars, win_sizes, n, factor);
		n++;
	}
	n = 0;
	while (n < vars.map.x_len)
	{
		column(vars, win_sizes, n, factor);
		n++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}
