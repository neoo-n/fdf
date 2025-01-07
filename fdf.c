/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:17 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 14:40:29 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_y(int *fd, char *file_name, t_map map)
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
			error_exit_perror(*fd, map, "Error closing fd (map_y)");
		}
		*fd = opening_file(file_name);
	}
	if (line)
		free(line);
	return (count);
}

static char	**collect_map(int *fd, char *file_name, t_map map)
{
	int		i;
	int		y_height;
	char	**map_read;

	i = 0;
	y_height = map_y(fd, file_name, map);
	if (y_height == 0)
		return (NULL);
	map_read = (char **)ft_calloc(y_height + 1, sizeof(char *));
	if (!map_read)
		return (NULL);
	while (i < y_height)
	{
		map_read[i] = get_next_line(*fd);
		i++;
	}
	map_read[i] = NULL;
	return (map_read);
}

static int	*atoi_while(int i, int *j, char **split_line, int **map_tab)
{
	while (split_line[*j])
	{
		map_tab[i][*j] = ft_atoi(split_line[*j]);
		(*j)++;
	}
	return (map_tab[i]);
}

static int	**map_atoi(t_map map, char **map_read)
{
	int		i;
	int		j;
	int 	**map_tab;
	char	**split_line;

	i = 0;
	map_tab = (int **)ft_calloc(map.y_len, sizeof(int *));
	if (!map_tab)
		return (NULL);
	while (i < map.y_len)
	{
		j = 0;
		split_line = ft_split(map_read[i], ' ');
		if (!split_line)
			return (NULL);
		map_tab[i] = (int *)ft_calloc(map.x_len, sizeof(int));
		if (!map_tab[i])
			return (freesplit(split_line), NULL);
		map_tab[i] = atoi_while(i, &j, split_line, map_tab);
		freesplit(split_line);
		i++;
	}
	return (map_tab);
}

void	ft_fdf(int fd, char *file_name)
{
	t_map	map;
	char	**map_read;

	map.map_tab = NULL;
	map.matrix = NULL;
	map.x_len = 0;
	map.y_len = 0;
	map.delay[0] = 0;
	map.delay[1] = 0;
	map.i_c[0] = 0;
	map.i_c[1] = 0;
	map.dxy[0] = 0;
	map.dxy[1] = 0;
	map_read = collect_map(&fd, file_name, map);
	if (!map_read)
		error_exit_write(fd, map, "Error creating map\n");
	while (map_read[map.y_len])
		map.y_len++;
	map.x_len = size_x(map_read);
	if (map.x_len == -1)
		error_exit_write(fd, map, "Error size of x\n");
	map.map_tab = map_atoi(map, map_read);
	if (!map.map_tab)
		error_exit_write(fd, map, "Error atoi\n");
	map.len_matrix = map.x_len * map.y_len;
	map.map_colours = getting_colours(map, map_read);
	if (!map.map_colours)
		error_exit_write(fd, map, "Error map_colours\n");
	freesplit(map_read);
	creating_map(map);
}
