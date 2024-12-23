/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:20:50 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/23 17:57:55 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	edges_line(t_vars vars, t_coord a, t_coord b, int factor)
{
	int		i;
	t_coord	coord_draw;
	int		delay[2];
	double	direction[3];

	i = 0;
	delay[0] = vars.win_sizes.x_middle - (vars.map.x_len * factor / 2);
	delay[1] = vars.win_sizes.y_middle - (vars.map.y_len * factor / 2);
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.x + i <= b.x)
	{
		coord_draw = param_equa_x(direction, a, i);
		coord_draw.y = a.y + ((b.y - a.y) * (coord_draw.x - a.x) / (b.x - a.x));
		printf("column : x : %i, y : %i\n", (int)coord_draw.x + delay[0], (int)coord_draw.y + delay[1]);
		my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
			coord_draw.y + delay[1], 0x00CC99FF);
		i++;
	}
}

void	edges_column(t_vars vars, t_coord a, t_coord b, int factor)
{
	int		i;
	t_coord	coord_draw;
	int		delay[2];
	double	direction[3];

	i = 0;
	delay[0] = vars.win_sizes.x_middle - (vars.map.x_len * factor / 2);
	delay[1] = vars.win_sizes.y_middle - (vars.map.y_len * factor / 2);
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.y + i <= b.y)
	{
		coord_draw = param_equa_y(direction, a, i);
		coord_draw.x = a.x + ((coord_draw.y - a.y) * (b.x - a.x) / (b.y - a.y));
		printf("column : x : %i, y : %i\n", (int)coord_draw.x + delay[0], (int)coord_draw.y + delay[1]);
		my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
			coord_draw.y + delay[1], 0x00CC99FF);
		i++;
	}
}
