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

t_coord	matrix_rotation(int x, int y, int z)
{
	t_coord	coord_right;

	coord_right.x = (x - y) / sqrt(2);
	coord_right.y = (x + y - 2 * z) / sqrt(6);
	coord_right.z = 0;
	return (coord_right);
}
