/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 18:08:36 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculation_coord(t_vars *vars)
{
	int		i;
	int		j;
	int		n;
	t_coord	coord;

	j = 0;
	n = 0;
	vars->map.matrix = (double **)ft_calloc(2, sizeof(double *));
	if (!vars->map.matrix)
		return ;
	vars->map.matrix[0] = (double *)ft_calloc(vars->map.len_matrix, sizeof(double));
	if (!vars->map.matrix[0])
		return (free(vars->map.matrix));
	vars->map.matrix[1] = (double *)ft_calloc(vars->map.len_matrix, sizeof(double));
	if (!vars->map.matrix[1])
		return (free(vars->map.matrix[0]), free(vars->map.matrix));
	while (j < vars->map.y_len)
	{
		i = 0;
		while (i < vars->map.x_len)
		{
			coord = matrix_rotation(i, j, vars->map.map_tab[j][i]);
			vars->map.matrix[0][n] = coord.x;
			vars->map.matrix[1][n] = coord.y;
			n++;
			i++;
		}
		j++;
	}
}

static void	factor_calcul(t_vars *vars, double ***matrix)
{
	int		i;
	double	x_distance;
	double	y_distance;
	int		factor;

	x_distance = vars->map.matrix[0][vars->map.x_len - 1]
		- vars->map.matrix[0][vars->map.len_matrix - vars->map.x_len];
	y_distance = vars->map.matrix[1][highest_elt(vars)]
		- vars->map.matrix[1][lowest_elt(vars)];
	factor = (vars->win_sizes.x_len * 0.9) / x_distance;
	if ((vars->win_sizes.y_height * 0.9) / y_distance < factor)
		factor = (vars->win_sizes.y_height * 0.9) / y_distance;
	i = 0;
	while (i < vars->map.len_matrix)
	{
		(*matrix)[0][i] *= factor;
		(*matrix)[1][i] *= factor;
		i++;
	}
}

void	drawing_map(t_vars *vars)
{
	double	middle_x;
	double	middle_y;

	calculation_coord(vars);
	factor_calcul(vars, &(vars->map.matrix));
	middle_x = vars->map.matrix[0][vars->map.x_len - 1]
		+ vars->map.matrix[0][vars->map.len_matrix - vars->map.x_len];
	middle_x /= 2;
	middle_y = vars->map.matrix[1][highest_elt(vars)] 
		+ vars->map.matrix[1][lowest_elt(vars)];
	middle_y /= 2;
	vars->map.delay[0] = vars->win_sizes.x_middle - (int)middle_x;
	vars->map.delay[1] = vars->win_sizes.y_middle - (int)middle_y;
	edges(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

