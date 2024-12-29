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

t_coord	matrix_rotation(t_coord co)
{
	double	alpha;
	double	beta;
	t_coord	coord_right;

	alpha = asin(tan(M_PI / 6.0));
	beta = M_PI / 4.0 ;
	printf("alpha : %f\n", beta);
	coord_right.x = (cos(beta) * co.x) - (sin(beta) * co.z);
//	coord_right.x = (co.x - co.z) / sqrt(2);
	coord_right.y = (sin(alpha) * sin(beta) * co.x) + (cos(alpha) * co.y) + (sin(alpha) * cos(beta) * co.z);
//	coord_right.y = (co.x + 2 * co.y + co.z) / sqrt(6);
	coord_right.z = 0;
//	printf("in matrix, x : %f, y : %f, z :%f\n", coord_right.x, coord_right.y, coord_right.z);
	return (coord_right);
}
