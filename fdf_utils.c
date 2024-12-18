/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:14:44 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/18 11:37:46 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	size_x(t_map map)
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
