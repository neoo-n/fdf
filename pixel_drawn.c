/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_drawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/20 18:12:51 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line(t_vars vars, t_map map, int j, int factor)
{
	int		i;
	t_coord	coord1;
	t_coord	coord2;

	i = 0;
	coord1.y = j * factor;
	coord2.y = j * factor;
	while (i < map.x_len - 1)
	{
		coord1.x = i * factor;
		coord2.x = (i + 1) * factor;
		coord1.z = map.map_tab[j][i] * factor;
		coord2.z = map.map_tab[j][i + 1] * factor;
		edges_line(vars, coord1, coord2);
		i++;
	}
}

static void	column(t_vars vars, t_map map, int i, int factor)
{
	int		j;
	t_coord	coord1;
	t_coord	coord2;

	j = 0;
	coord1.x = i * factor;
	coord2.x = i * factor;
	while (j < map.y_len - 1)
	{
		coord1.y = j * factor;
		coord2.y = (j + 1) * factor;
		coord1.z = map.map_tab[j][i] * factor;
		coord2.z = map.map_tab[j + 1][i] * factor;
		edges_column(vars, coord1, coord2);
		j++;
	}
}

void	drawing_map(t_vars vars, t_map map, t_win_size win_sizes)
{
	int	n;
	int	factor;

	n = 0;
	factor = (win_sizes.x_len * 0.6)/ (map.x_len + 1);
	if ((win_sizes.y_height * 0.6) / (map.y_len + 1) < factor)
		factor = (win_sizes.y_height * 0.6) / (map.y_len + 1);
//	factor = 1;
	printf("factor : %i\n", factor);
	if (map.x_len == 1 && map.y_len == 1)
	{
		my_mlx_pixel_put(&(vars.img), win_sizes.x_middle * factor,
			win_sizes.y_middle * factor, 0x00CC99FF);
	}
	while (n < map.y_len)
	{
		line(vars, map, n, factor);
		n++;
	}
	n = 0;
	while (n < map.x_len)
	{
		column(vars, map, n, factor);
		n++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}
