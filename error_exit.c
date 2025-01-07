/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:30 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/07 17:36:27 by dvauthey         ###   ########.fr       */
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

void	error_exit_perror(int fd, t_map map, char *message)
{
	if (fd > -1)
		close(fd);
	if (map.map_tab)
		freeatoi(map.map_tab, map.y_len);
	if (map.matrix)
	{
		free(map.matrix[1]);
		free(map.matrix[0]);
		free(map.matrix);
	}
	perror(message);
	exit(EXIT_FAILURE);
}

void	error_exit_write(int fd, t_map map, char *message)
{
	if (fd > -1)
		close(fd);
	if (map.map_tab)
		freeatoi(map.map_tab, map.y_len);
	if (map.matrix)
	{
		free(map.matrix[1]);
		free(map.matrix[0]);
		free(map.matrix);
	}
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
