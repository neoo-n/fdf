/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/09 15:28:55 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	matrix_in_coord(t_coord *coord, int *index, int *n, t_vars *vars)
{
	*coord = matrix_rotation(index[0], index[1],
			vars->map.map_tab[index[1]][index[0]], vars);
	vars->map.matrix[0][*n] = coord->x;
	vars->map.matrix[1][*n] = coord->y;
	(*n)++;
	index[0]++;
	return (index[0]);
}

static void	calculation_coord(t_vars *vars)
{
	int		index[2];
	int		n;
	t_coord	coord;

	index[1] = 0;
	n = 0;
	vars->map.matrix = (double **)ft_calloc(2, sizeof(double *));
	if (!vars->map.matrix)
		return ;
	vars->map.matrix[0] = (double *)ft_calloc(vars->map.len_mx, sizeof(double));
	if (!vars->map.matrix[0])
		return (free(vars->map.matrix));
	vars->map.matrix[1] = (double *)ft_calloc(vars->map.len_mx, sizeof(double));
	if (!vars->map.matrix[1])
		return (free(vars->map.matrix[0]), free(vars->map.matrix));
	while (index[1] < vars->map.y_len)
	{
		index[0] = 0;
		while (index[0] < vars->map.x_len)
		{
			index[0] = matrix_in_coord(&coord, index, &n, vars);
		}
		index[1]++;
	}
}

static void	factor_calcul(t_vars *vars, double ***matrix)
{
	int		i;
	double	x_distance;
	double	y_distance;
	int		factor;

	if (vars->map.len_mx == 1)
		return ;
	x_distance = vars->map.matrix[0][vars->map.x_len - 1]
		- vars->map.matrix[0][vars->map.len_mx - vars->map.x_len];
	y_distance = vars->map.matrix[1][highest_elt(vars)]
		- vars->map.matrix[1][lowest_elt(vars)];
	if (x_distance == 0 || y_distance == 0)
		error_exit_vars(vars, "Error factor (x / 0)\n", 0);
	factor = (vars->win_sizes.x_len * 0.9) / x_distance;
	if ((vars->win_sizes.y_height * 0.9) / y_distance < factor)
		factor = (vars->win_sizes.y_height * 0.9) / y_distance;
	i = 0;
	while (i < vars->map.len_mx)
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
	if (!vars->map.matrix)
		error_exit_vars(vars, "Error matrix\n", 0);
	factor_calcul(vars, &(vars->map.matrix));
	middle_x = vars->map.matrix[0][vars->map.x_len - 1]
		+ vars->map.matrix[0][vars->map.len_mx - vars->map.x_len];
	middle_x /= 2;
	middle_y = vars->map.matrix[1][highest_elt(vars)]
		+ vars->map.matrix[1][lowest_elt(vars)];
	middle_y /= 2;
	vars->map.delay[0] = vars->win_sizes.x_middle - (int)middle_x;
	vars->map.delay[1] = vars->win_sizes.y_middle - (int)middle_y;
	edges(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
