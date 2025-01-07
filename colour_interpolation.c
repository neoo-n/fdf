/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_interpolation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:55:15 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 14:29:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_colour	get_rgb(t_vars vars, int i)
{
	t_colour	c;

	c.c = vars.map.map_colours[vars.map.i_c[i]];
	c.r = (c.c >> 16) & 0xFF;
	c.g = (c.c >> 8) & 0xFF;
	c.b = c.c & 0xFF;
	return (c);
}

static t_colour	colour_calcul(t_colour c1, t_colour c2, double factor)
{
	t_colour	c;
	
	c.r = c1.r + (c2.r - c1.r) * factor;
	c.g = c1.g + (c2.g - c1.g) * factor;
	c.b = c1.b + (c2.b - c1.b) * factor;
	c.c = (c.r << 16) | (c.g << 8) | c.b;
	return (c);
}

int	interpolation(t_vars vars, int *x, int *y)
{
	t_colour	c1;
	t_colour	c2;
	t_colour	c_final;
	int			pt_original[2];
	double		factor;

	c1 = get_rgb(vars, 1);
	c2 = get_rgb(vars, 0);
	if (c1.c == c2.c)
		return (c1.c);
	pt_original[0] = vars.map.matrix[0][vars.map.i_c[0]];
	pt_original[1] = vars.map.matrix[1][vars.map.i_c[0]];
	factor = (pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2)) / 
		(pow(x[1] - pt_original[0], 2) + pow(y[1] - pt_original[1], 2));
	factor = sqrt(factor);
	c_final = colour_calcul(c1, c2, factor);
	return (c_final.c);
}
