/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:57:17 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/15 17:41:51 by dvauthey         ###   ########.fr       */
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

void	ft_fdf(int fd, char *file_name)
{
	char **map;

	map = collect_map(&fd, file_name);
	if (!map)
	{
		close (fd);
		write(1, "Error creating map\n", 19);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 55; j++)
			ft_printf("%c", map[i][j]);
		ft_printf("\n");
	}
}