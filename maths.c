/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:50:55 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/09 15:19:09 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	matrix_rotation(int x, int y, int z, t_vars *vars)
{
	double	sq2;
	double	sq6;
	t_coord	coord_right;

	sq2 = sqrt(2);
	sq6 = sqrt(6);
	if (sq2 == 0 || sq6 == 0)
		error_exit_vars(vars, "Error sqrt in rot\n", 0);
	coord_right.x = (x - y) / sq2;
	coord_right.y = (x + y - 2 * z) / sq6;
	coord_right.z = 0;
	return (coord_right);
}

static int	occurence(char c)
{
	int		i;
	char	*str;
	char	*str1;

	i = 0;
	str = "0123456789ABCDEF";
	str1 = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] == c || str1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	str_to_hexaint(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
	{
		result = result * 16 + occurence(str[i]);
		i++;
	}
	return (result);
}
