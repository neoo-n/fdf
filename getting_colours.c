/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:50:26 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/08 10:50:26 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	colours_cpy(char *split_line)
{
	int		start;
	int		colour;

	start = 0;
	colour = 16777215;
	while (split_line[start])
	{
		if (split_line[start] == 'x' || split_line[start] == 'X')
			return (str_to_hexaint(split_line + start + 1));
		start++;
	}
	return (colour);
}

static void	in_while(int *colours, char *split_line, int *j, int *k)
{
	(*colours) = colours_cpy(split_line);
	(*j)++;
	(*k)++;
}

static void	free_colours(int *colours, t_map *map, char **split_line, char **mr)
{
	free(colours);
	if (map->map_tab)
		freeatoi(map->map_tab, map->y_len);
	if (map->matrix)
	{
		free(map->matrix[1]);
		free(map->matrix[0]);
		free(map->matrix);
	}
	if (mr)
		freesplit(mr);
	write(1, "Error colour (-1)\n", 18);
	if (split_line)
		freesplit(split_line);
	exit(EXIT_FAILURE);
}

int	*getting_colours(t_map *map, char **map_read)
{
	t_ijk	ijk;
	int		*colours;
	char	**split_line;

	ijk.i = 0;
	ijk.k = 0;
	colours = (int *)ft_calloc(map->len_mx, sizeof(int));
	if (!colours)
		return (NULL);
	while (ijk.i < map->y_len)
	{
		ijk.j = 0;
		split_line = ft_split(map_read[ijk.i], ' ');
		if (!split_line)
			return (NULL);
		while (split_line[ijk.j])
		{
			in_while(&(colours[ijk.k]), split_line[ijk.j], &ijk.j, &ijk.k);
			if (colours[ijk.k - 1] == -1)
				free_colours(colours, map, split_line, map_read);
		}
		freesplit(split_line);
		ijk.i++;
	}
	return (colours);
}
