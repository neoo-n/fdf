/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:20:50 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/21 19:12:54 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

/*static double	*delay_calcul(t_vars vars, t_win_size win_sizes)
{
	double	delay[2];
	double	middle[2];
	
	middle[0] = vars.map.x_len / 2;
	middle[1] = vars.map.y_len / 2;
	delay[0] = win_sizes.x_middle - middle[0];
	delay[1] = win_sizes.y_middle - middle[1];
	return (delay);
}*/

static void	lines_draw(t_vars vars, double *delay, t_coord a, int i)
{
	double	num_float;
	t_coord coord_draw;

	coord_draw = param_equa_x(direction, a, i);
	num_float = (int)coord_draw.y;
	if (coord_draw.y != num_float)
	{
		my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
			num_float + 1 + delay[1], 0x00CC99FF);
	}
	my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
		coord_draw.y + delay[1], 0x00CC99FF); 
}

void	edges_line(t_vars vars, t_win_size win_sizes, t_coord a, t_coord b)
{
	int		i;
	double	*delay;
	double	direction[3];

	i = 0;
	delay[0] = 0;
	delay[0] = win_sizes.x_middle - (vars.map.x_len / 2);
	delay[1] = win_sizes.y_middle - (vars.map.y_len / 2);
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.x + i <= b.x)
	{
		lines_draw(vars, delay, a, i);
		i++;
	}
}

static void	column_draw(t_vars vars, double *delay, t_coord a, int i)
{
	double	num_float;
	t_coord coord_draw;

	coord_draw = param_equa_y(direction, a, i);
	num_float = (int)coord_draw.x;
	if (coord_draw.x != num_float)
	{
		my_mlx_pixel_put(&(vars.img), num_float + 1 + delay[0],
			coord_draw.y + delay[1], 0x00CC99FF);
	}
	my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
		coord_draw.y + delay[1], 0x00CC99FF); 
}

void	edges_column(t_vars vars, t_win_size win_sizes, t_coord a, t_coord b)
{
	int		i;
	double	*delay;
	double	direction[3];
	double	num_float;

	i = 0;
	delay[0] = 0;
	delay[0] = win_sizes.x_middle - (vars.map.x_len / 2);
	delay[1] = win_sizes.y_middle - (vars.map.y_len / 2);
	direction[0] = b.x - a.x; 
	direction[1] = b.y - a.y; 
	direction[2] = b.z - a.z;
	while (a.y + i <= b.y)
	{
		column_draw(vars, delay, a, i);
		i++;
	}
}
