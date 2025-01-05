/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:11:51 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/05 16:52:20 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static void	x_moving(t_vars vars, int *x, int *y, int *sxy)
{
	int	dx;
	int	dy;
	int	param;

	dx = abs(x[1] - x[0]);
	dy = abs(y[1] - y[0]);
	param = 2 * dy - dx;
	while (x[0] != x[1])
	{
		x[0] += sxy[0];
		dx = abs(x[1] - x[0]);
		my_mlx_pixel_put(&vars.img, x[0] + vars.map.delay[0], y[0] + vars.map.delay[1], vars.map.map_colours[vars.map.index_c[0]]);
		if (param < 0)
		{
			param += 2 * dy;
		}
		else
		{
			y[0] += sxy[1];
			dy = abs(y[1] - y[0]);
			param += 2 * dy - 2 * dx;
		}
	}
	my_mlx_pixel_put(&vars.img, x[0] + vars.map.delay[0], y[0] + vars.map.delay[1], vars.map.map_colours[vars.map.index_c[1]]);
}

static void	y_moving(t_vars vars, int *x, int *y, int *sxy)
{
	int	dx;
	int	dy;
	int	param;

	dx = abs(x[1] - x[0]);
	dy = abs(y[1] - y[0]);
	param = 2 * dx - dy;
	while (y[0] != y[1])
	{
		y[0] += sxy[1];
		dy = abs(y[1] - y[0]);
		my_mlx_pixel_put(&vars.img, x[0] + vars.map.delay[0], y[0] + vars.map.delay[1], vars.map.map_colours[vars.map.index_c[0]]);
		if (param < 0)
		{
			param += 2 * dx;
		}
		else
		{
			x[0] += sxy[0];
			dx = abs(x[1] - x[0]);
			param += 2 * dx - 2 * dy;
		}
	}
	my_mlx_pixel_put(&vars.img, x[0] + vars.map.delay[0], y[0] + vars.map.delay[1], vars.map.map_colours[vars.map.index_c[1]]);
}

static void	bresenham(t_vars vars, int i, int j)
{
	int		x[2];
	int		y[2];
	int		sxy[2];
	double	m;

	x[0] = vars.map.matrix[0][i];
	x[1] = vars.map.matrix[0][j];
	y[0] = vars.map.matrix[1][i];
	y[1] = vars.map.matrix[1][j];
	if (x[1] > x[0])
		sxy[0] = 1;
	else
		sxy[0] = -1;
	if (y[1] > y[0])
		sxy[1] = 1;
	else
		sxy[1] = -1;
	m = (double)(y[1] - y[0]) / (double)(x[1] - x[0]);
	if (m >= -1.0 && m <= 1.0)
		x_moving(vars, x, y, sxy);	
	else
		y_moving(vars, x, y, sxy);
}

void	edges(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.map.len_matrix)
	{
		if ((i + 1) % vars.map.x_len)
		{
			vars.map.index_c[0] = i;
			vars.map.index_c[1] = i + 1;
			bresenham(vars, i, i + 1);
		}
		if (i < vars.map.len_matrix - vars.map.x_len)
		{
			vars.map.index_c[0] = i;
			vars.map.index_c[1] = i + vars.map.x_len;
			bresenham(vars, i, i + vars.map.x_len);
		}
		i++;
	}
}