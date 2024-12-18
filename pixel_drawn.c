/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_drawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:29 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/18 16:06:15 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	edges_h(t_vars vars, int x_start, int x_end, int y)
{
	int	i;

	i = 0;
	while (x_start + i < x_end)
	{
		pixel_drawn(vars, x_start + i, y);
		i++;
	}
}

void	edges_v(t_vars vars, int x, int y_start, int y_end)
{
	int	i;

	i = 0;
	while (y_start + i < y_end)
	{
		pixel_drawn(vars, x, y_start + i);
		i++;
	}
}
