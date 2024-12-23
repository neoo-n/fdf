/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:10:17 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/23 14:49:35 dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	matrix_rotation(t_coord coord)
{
	t_coord	coord_right;

	coord_right.x = (coord.x + coord.z) / sqrt(2);
	coord_right.y = (coord.x + 2 * coord.y + coord.z) / sqrt(6);
	coord_right.z = (coord.x + coord.y + coord.z) / sqrt(3);
	return (coord_right);
}

t_coord	param_equa_x(double *direction, t_coord a, int i)
{
	double	t;
	t_coord	coord_draw;
	t_coord	coord_right;


	t = 0;
	coord_draw.x = a.x + i;
	if (direction[0] != 0)
		t = i / direction[0];
	coord_draw.y = direction[1] * t + a.y;
	coord_draw.z = direction[2] * t + a.z;
	coord_right = matrix_rotation(coord_draw);
	return (coord_right);
}

t_coord	param_equa_y(double *direction, t_coord a, int i)
{
	double	t;
	t_coord	coord_draw;
	t_coord	coord_right;

	t = 0;
	coord_draw.y = a.y + i;
	if (direction[1] != 0)
		t = i / direction[1];
	coord_draw.x = direction[0] * t + a.x;
	coord_draw.z = direction[2] * t + a.z;
	coord_right = matrix_rotation(coord_draw);
	return (coord_right);
}
