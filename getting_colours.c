/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:31:30 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 17:20:14 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

static int	is_coloured(char **split_line, int i)
{
	int	j;
	int	len_line;

	j = 0;
	len_line = ft_strlen(split_line[i]);
	if (len_line == 0)
		return (-1);
	while (split_line[i][j] && j < len_line - 2)
	{
		printf("j : %i\n", j);
		if (!ft_strncmp("0x", split_line[i] + j, 2))
			return (j);
		j++;
	}
	printf("meh\n");
	return (-1);
}

static void	colours_cpy(int **colours, int i, char *split_line)
{
	int	start;

	start = 0;
	printf("bouh\n");
	while (split_line[start] != 'x')
		start++;
	start--;
	*colours[i] = str_to_hexaint(split_line + start);
}

static void	cpy_white(int **colours, int i)
{
	int	white;

	white = str_to_hexaint("0xFFFFFFFF");
	*colours[i] = white;
}

int	*getting_colours(t_map map, char **map_read)
{
	int		i;
	int		j;
	int		*colours;
	char	**split_line;

	i = 0;
	colours = (int *)ft_calloc(1, sizeof(int));
	if (!colours)
		return (NULL);
	while (i < map.y_len)
	{
		j = 0;
		split_line = ft_split(map_read[i], ' ');
		if (!split_line)
			return (NULL);
		while (split_line[j])
		{
			if (is_coloured(split_line, j) != -1)
				colours_cpy(&colours, (i + 1) * j + (3 * i), split_line[j]);
			else
				cpy_white(&colours, (i + 1) * j + (3 * i));
			printf("colours[%i] : %i\n", (i + 1) * j + (3 * i), colours[(i + 1) * j + (3 * i)]);
			j++;
		}
		freesplit(split_line);
		i++;
	}
	return (colours);
}
