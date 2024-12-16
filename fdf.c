/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:17 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/16 17:27:03 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_y(int *fd, char *file_name)
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
		if (close (*fd) == -1)
			error_exit(*fd, NULL, "Error closing fd (map_y)");
		*fd = opening_file(file_name);
	}
	return (count);
}
static char	**collect_map(int *fd, char *file_name)
{
	int		i;
	int		y_height;
	char	**map;

	i = 0;
	y_height = map_y(fd, file_name);
	if (y_height == 0)
		return (NULL);
	map = (char **)ft_calloc(y_height + 1, sizeof(char *));
	while (i < y_height)
	{
		map[i] = get_next_line(*fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int	**map_atoi(t_map map)
{
	int		i;
	int		j;
	int		start;
	int 	**map_tab;
	char	**split_line;

	i = 0;
	start = 0;
	map_tab = (int **)ft_calloc(map.y_len, sizeof(int *));
	if (!map_tab)
		return (NULL);
	while (map.map_read[i])
	{
		j = 0;
		split_line = ft_split(map.map_read[i], ' ');
		if (!split_line)
			return (NULL);
		while (split_line[j])
		{
			map_tab[i][j] = ft_atoi(split_line[j]);
			j++;
		}
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
	return (i);
}

void	ft_fdf(int fd, char *file_name)
{
	t_map	map;

	map.map_tab = NULL;
	map.x_len = 0;
	map.y_len = 0;
	map.map_read = collect_map(&fd, file_name);
	if (!map.map_read)
	{
		close (fd);
		write(1, "Error creating map\n", 19);
		exit(EXIT_FAILURE);
	}
	while (map.map_read[map.y_len])
		map.y_len++;
	map.map_tab = map_atoi(map);
	map.x_len = size_x(map);
	if (map.x_len == -1)
	{
		close (fd);
		write(1, "Error size of x\n", 16);
		exit(EXIT_FAILURE);
	}
	creating_map_2d(map.map_read);
}
