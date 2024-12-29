/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:20:50 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/29 18:52:14 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	edges_line(t_vars vars, t_coord a, t_coord b, int factor)
{
	int		i;
	t_coord	coord_draw;
	int		delay[2];

	i = 0;
	delay[0] = vars.win_sizes.x_middle - (vars.map.x_len * factor / 2);
	delay[1] = vars.win_sizes.y_middle - (vars.map.y_len * factor / 2);
	a = matrix_rotation(a);
	b = matrix_rotation(b);
	while (a.x + i <= b.x)
	{
		coord_draw.x = a.x + i;
		coord_draw.y = a.y + ((coord_draw.x - a.x) * (b.y - a.y) / (b.x - a.x));
		coord_draw.z = 0;
	//	printf("line : x : %i, y : %i\n\n", (int)coord_draw.x, (int)coord_draw.y);
		my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
			coord_draw.y + delay[1], 0x00CC99FF);
		i++;
	}
}

void	edges_column(t_vars vars, t_coord a, t_coord b, int factor)
{
	int		i;
	t_coord	coord_draw;
	int		delay[2];

	i = 0;
	delay[0] = vars.win_sizes.x_middle - (vars.map.x_len * factor / 2);
	delay[1] = vars.win_sizes.y_middle - (vars.map.y_len * factor / 2);
	a = matrix_rotation(a);
	b = matrix_rotation(b);
	while (a.y + i <= b.y)
	{
		coord_draw.y = a.y + i;
		coord_draw.x = a.x + ((coord_draw.y - a.y) * (b.x - a.x) / (b.y - a.y));
		coord_draw.z = 0;
	//	printf("column : x : %i, y : %i\n\n", (int)coord_draw.x, (int)coord_draw.y);
		my_mlx_pixel_put(&(vars.img), coord_draw.x + delay[0],
			coord_draw.y + delay[1], 0x00CC99FF);
		i++;
	}
}
