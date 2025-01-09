/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:14:44 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/09 14:20:15 by dvauthey         ###   ########.fr       */
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

int	map_y(int *fd, char *file_name, t_map *map)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(*fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(*fd);
	}
	if (count != 0)
	{
		if (close(*fd) == -1)
		{
			if (line)
				free(line);
			error_exit(map, "Error closing fd (map_y)", 1, NULL);
		}
		*fd = opening_file(file_name);
	}
	if (line)
		free(line);
	return (count);
}

int	highest_elt(t_vars *vars)
{
	int	i;
	int	highest;
	int	highest_index;

	i = 0;
	highest = vars->map.matrix[1][0];
	highest_index = 0;
	while (i < vars->map.len_mx)
	{
		if (highest < vars->map.matrix[1][i])
		{
			highest_index = i;
			highest = vars->map.matrix[1][i];
		}
		i++;
	}
	return (highest_index);
}

int	lowest_elt(t_vars *vars)
{
	int	i;
	int	lowest;
	int	lowest_index;

	i = 0;
	lowest = vars->map.matrix[1][0];
	lowest_index = 0;
	while (i < vars->map.len_mx)
	{
		if (lowest > vars->map.matrix[1][i])
		{
			lowest_index = i;
			lowest = vars->map.matrix[1][i];
		}
		i++;
	}
	return (lowest_index);
}
