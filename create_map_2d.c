/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:04:49 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/17 11:05:10 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	creating_map_2d(t_map map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map.y_len)
	{
		i = 0;
		while (i < map.x_len)
		{
			ft_printf("%i\n", map.map_tab[j][i]);
			i++;
		}
		j++;
	}
}