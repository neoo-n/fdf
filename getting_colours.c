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

static int	is_coloured(char *split_line)
{
	int	i;
	int	len_line;

	i = 0;
	len_line = ft_strlen(split_line);
	if (len_line == 0)
		return (-1);
	while (split_line[i] && i < len_line - 2)
	{
		printf("j : %i\n", i);
		if (!ft_strncmp("0x", split_line + i, 2))
			return (i);
		i++;
	}
	return (-1);
}

static int	colours_cpy(char *split_line)
{
	int		start;
	int		colour;
	char	*white;

	start = 0;
	white = "FFFFFF";
	colour = str_to_hexaint(white);
	if (is_coloured(split_line) != -1)
	{	
		while (split_line[start] != 'x')
			start++;
		start++;
		colour = str_to_hexaint(split_line + start);
	}
	return (colour);
}

void	in_while(int *colours, char *split_line, int *j, int *k)
{
	(*colours) = colours_cpy(split_line);
	(*j)++;
	(*k)++;
}

int	*getting_colours(t_map map, char **map_read)
{
	int		i;
	int		j;
	int		k;
	int		*colours;
	char	**split_line;

	i = 0;
	k = 0;
	colours = (int *)ft_calloc(map.len_matrix, sizeof(int));
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
			in_while(&(colours[k]), split_line[j], &j, &k);
		}
		freesplit(split_line);
		i++;
	}
	return (colours);
}
