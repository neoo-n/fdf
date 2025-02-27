/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:17 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/09 15:19:53 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map)
{
	map->map_tab = NULL;
	map->matrix = NULL;
	map->map_colours = NULL;
	map->x_len = 0;
	map->y_len = 0;
	map->delay[0] = 0;
	map->delay[1] = 0;
	map->i_c[0] = 0;
	map->i_c[1] = 0;
	map->dxy[0] = 0;
	map->dxy[1] = 0;
}

static char	**collect_map(int *fd, char *file_name, t_map *map)
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

static int	**map_atoi(t_map *map, char **map_read)
{
	int		i;
	int		j;
	int		**map_tab;
	char	**split_line;

	i = 0;
	map_tab = (int **)ft_calloc(map->y_len, sizeof(int *));
	if (!map_tab)
		return (NULL);
	while (i < map->y_len)
	{
		j = 0;
		split_line = ft_split(map_read[i], ' ');
		if (!split_line)
			return (NULL);
		map_tab[i] = (int *)ft_calloc(map->x_len, sizeof(int));
		if (!map_tab[i])
			return (freesplit(split_line), freeatoi(map_tab, i), NULL);
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

	init_map(&map);
	map_read = collect_map(&fd, file_name, &map);
	if (!map_read)
		error_map_read(fd, "Error creating map\n");
	if (close(fd) == -1)
		error_exit(&map, "Error closing file", 1, map_read);
	while (map_read[map.y_len])
		map.y_len++;
	map.x_len = size_x(map_read);
	if (map.x_len < -1)
		error_exit(&map, "Error size of x\n", 0, map_read);
	map.map_tab = map_atoi(&map, map_read);
	if (!map.map_tab)
		error_exit(&map, "Error atoi\n", 0, map_read);
	map.len_mx = map.x_len * map.y_len;
	map.map_colours = getting_colours(&map, map_read);
	if (!map.map_colours)
		error_exit(&map, "Error map_colours\n", 0, map_read);
	freesplit(map_read);
	creating_map(&map);
}
