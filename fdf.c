/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:17 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/17 11:54:04 by dvauthey         ###   ########.fr       */
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

static int	**map_atoi(t_map map)
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
		ft_printf("map.map_read[%i] : %s\n", i, map.map_read[i]);
		split_line = ft_split(map.map_read[i], ' ');
		if (!split_line)
			return (NULL);
		map_tab[i] = (int *)ft_calloc(1, sizeof(int));
		if (!map_tab[i])
			return (freesplit(split_line), NULL);
		while (split_line[j])
		{
			ft_printf("split_line[%i] : %s\n", j, split_line[j]);
			map_tab[i][j] = ft_atoi(split_line[j]);
			j++;
		}
		ft_printf("bruhhhhhhhhh\n");
		freesplit(split_line);
		ft_printf("help\n");
		i++;
	}
	return (map_tab);
}

static int	size_x(t_map map)
{
	int		i;
	char	**split_line;

	i = 0;
	split_line = ft_split(map.map_read[0], ' ');
	if (!split_line)
		return (-1);
	while (split_line[i])
		i++;
	freesplit(split_line);
	return (i);
}

void	ft_fdf(int fd, char *file_name)
{
	t_map	map;

	map.map_read = NULL;
	map.map_tab = NULL;
	map.x_len = 0;
	map.y_len = 0;
	map.map_read = collect_map(&fd, file_name, map);
	if (!map.map_read)
		error_exit_write(fd, map, "Error creating map\n");
	while (map.map_read[map.y_len])
		map.y_len++;
	map.x_len = size_x(map);
	if (map.x_len == -1)
		error_exit_write(fd, map, "Error size of x\n");
	map.map_tab = map_atoi(map);
	if (!map.map_tab)
		error_exit_write(fd, map, "Error atoi\n");
	creating_map_2d(map);
}
