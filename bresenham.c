/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:11:51 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/03 15:13:31 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	quadran_calcul(double *x, double *y, double m, int **sxy)
{
	if (m > -1 && m < 1)
	{
		if (x[1] > x[0])
			*sxy[0] = 1;
		if (x[1] < x[0])
			*sxy[0] = -1;
	}
	else
	{
		if (y[1] > y[0])
			*sxy[1] = -1;
		if (y[1] < y[0])
			*sxy[1] = 1;
	}
}

static void	x_moving(t_vars vars, double *x, double *y, int *delay)
{
	double	param;

	param = 2 * (y[1] - y[0]) - (x[1] - x[0]);
	while (y[0] <= y[1] && x[0] <= x[1])
	{
		my_mlx_pixel_put(&vars.img, x[0] + delay[0], y[0] + delay[1], 0x00FFFFfF);
		if (param < 0)
		{
			x[0]++;
			param += 2 * (y[1] - y[0]);
		}
		else
		{
			x[0]++;
			y[0]++;
			param += 2 * (y[1] - y[0]) - 2 * (x[1] - x[0]);
		}
	}
}

static void	bresenham(t_vars vars, int i, int j, int *delay)
{
	double	x[2];
	double	y[2];
	int		sxy[2];
	double	m;

	x[0] = vars.map.matrix[0][i];
	x[1] = vars.map.matrix[0][j];
	y[0] = vars.map.matrix[1][i];
	y[1] = vars.map.matrix[1][j];
	sxy[0] = 0;
	sxy[1] = 0;
	m = (y[1] - y[0]) / (x[1] - x[0]);
	quadran_calcul(x, y, m, &sxy);
	if (sxy[0])
	{
		
	}	
}

void	edges(t_vars vars, int *delay)
{
	int	i;

	i = 0;
	while (i < vars.map.len_matrix)
	{
		if ((i + 1) % vars.map.x_len)
			bresenham(vars, i, i + 1, delay);
		if (i < vars.map.len_matrix - vars.map.x_len)
		i++;
	}
}