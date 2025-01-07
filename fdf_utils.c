/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:14:44 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 14:29:43 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	size_x(char **map_read)
{
	int		i;
	char	**split_line;

	i = 0;
	split_line = ft_split(map_read[0], ' ');
	if (!split_line)
		return (-1);
	while (split_line[i])
		i++;
	freesplit(split_line);
	return (i);
}

int	highest_elt(t_vars vars)
{
	int	i;
	int	highest;
	int	highest_index;

	i = 0;
	highest = vars.map.matrix[1][0];
	highest_index = 0;
	while (i < vars.map.len_matrix)
	{
		if (highest < vars.map.matrix[1][i])
		{
			highest_index = i;
			highest = vars.map.matrix[1][i];
		}
		i++;	
	}
	return (highest_index);
}

int	lowest_elt(t_vars vars)
{
	int	i;
	int	lowest;
	int	lowest_index;

	i = 0;
	lowest = vars.map.matrix[1][0];
	lowest_index = 0;
	while (i < vars.map.len_matrix)
	{
		if (lowest > vars.map.matrix[1][i])
		{
			lowest_index = i;
			lowest = vars.map.matrix[1][i];
		}
		i++;	
	}
	return(lowest_index);
}

static int	occurence(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	str_to_hexaint(char *str)
{
	int		i;
	char	*hexa;
	int		len_str;
	int		result;

	i = 0;
	hexa = "0123456789ABCDEF";
	len_str = ft_strlen(str);
	result = 0;
	if (!str)
		return (0);
	while (len_str - 1 - i >= 0)
	{
		result += pow(16, i) * occurence(hexa, str[len_str - 1 - i]);
		i++;
	}
	return (result);
}
