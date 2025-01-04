/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:14:44 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/04 18:18:12 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

void	freesplit(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	freeatoi(int **tab, int y)
{
	int	i;
	
	i = 0;
	while (i < y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
