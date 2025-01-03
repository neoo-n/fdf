/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/03 02:01:20 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static double	**calculation_coord(t_vars vars)
{
	int		i;
	int		j;
	int		n;
	t_coord	coord;
	double	**matrix;

	j = 0;
	n = 0;
	matrix = (double **)ft_calloc(2, sizeof(double *));
	matrix[0] = (double *)ft_calloc(vars.map.len_matrix, sizeof(double));
	matrix[1] = (double *)ft_calloc(vars.map.len_matrix, sizeof(double));
	while (j < vars.map.y_len)
	{
		i = 0;
		while (i < vars.map.x_len)
		{
			coord = matrix_rotation(i, j, vars.map.map_tab[j][i]);
			matrix[0][n] = coord.x;
			matrix[1][n] = coord.y;
			n++;
			i++;
		}
		j++;
	}
	return (matrix);
}

static void	factor_calcul(t_vars vars, double ***matrix)
{
	int		i;
	double	x_distance;
	double	y_distance;
	int		factor;

	printf("vars : %f\n", vars.map.matrix[0][vars.map.len_matrix - 1]);
	x_distance = vars.map.matrix[0][vars.map.len_matrix - 1]
		- vars.map.matrix[0][vars.map.len_matrix - vars.map.x_len];
	y_distance = vars.map.matrix[1][vars.map.len_matrix - 1];
	factor = (vars.win_sizes.x_len * 0.65) / x_distance;
	if ((vars.win_sizes.y_height * 0.65) / y_distance < factor)
		factor = (vars.win_sizes.y_height * 0.65) / y_distance;
	i = 0;
	while (i < vars.map.len_matrix)
	{
		(*matrix)[0][i] *= factor;
		(*matrix)[1][i] *= factor;
		i++;
	}
}

void	drawing_map(t_vars vars)
{
	int	delay[2];
	double	middle_x;
	double	middle_y;

	vars.map.matrix = calculation_coord(vars);
	factor_calcul(vars, &(vars.map.matrix));
	middle_x = vars.map.matrix[0][vars.map.len_matrix - 1]
		- vars.map.matrix[0][vars.map.len_matrix - vars.map.x_len];
	middle_x /= 2;
	middle_y = vars.map.matrix[1][vars.map.len_matrix - 1] / 2;
	delay[0] = (int)(vars.win_sizes.x_middle - middle_x);
	delay[1] = (int)(vars.win_sizes.y_middle - middle_y);
	for(int i = 0; i < vars.map.len_matrix; i++)
	{
		my_mlx_pixel_put(&vars.img, vars.map.matrix[0][i] + delay[0], vars.map.matrix[1][i] + delay[1], 0x00CC99FF);
		printf("matrix i : (%f, %f)\n", vars.map.matrix[0][i] + delay[0], vars.map.matrix[1][i] + delay[1]);
	}
}

