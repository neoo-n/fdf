/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:20:50 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/20 15:40:24 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	edges_line(t_vars vars, t_coord a, t_coord b)
{
	int		i;
	double	direction[3];
	t_coord coord_draw;
	double	num_float;

	i = 0;
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.x + i <= b.x)
	{
		coord_draw = param_equa_x(direction, a, i);
		num_float = (int)coord_draw.y;
		if (coord_draw.y != num_float)
			my_mlx_pixel_put(&(vars.img), coord_draw.x, num_float + 1, 0x00CC99FF);
		my_mlx_pixel_put(&(vars.img), coord_draw.x, coord_draw.y, 0x00CC99FF); 
		i++;
	}
}

void	edges_column(t_vars vars, t_coord a, t_coord b)
{
	int		i;
	double	direction[3];
	t_coord coord_draw;
	double	num_float;

	i = 0;
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.y + i <= b.y)
	{
		coord_draw = param_equa_y(direction, a, i);
		num_float = (int)coord_draw.x;
		if (coord_draw.x != num_float)
			my_mlx_pixel_put(&(vars.img), num_float + 1, coord_draw.y, 0x00CC99FF);
		my_mlx_pixel_put(&(vars.img), coord_draw.x, coord_draw.y, 0x00CC99FF); 
		i++;
	}
}
