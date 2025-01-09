/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:30 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/08 16:15:29 by dvauthey         ###   ########.fr       */
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

void	error_map_read(int fd, char *message)
{
	if (fd > -1)
		close(fd);
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	error_exit(t_map *map, char *message, int is_perror, char **map_read)
{
	if (map->map_tab)
		freeatoi(map->map_tab, map->y_len);
	if (map->matrix)
	{
		free(map->matrix[1]);
		free(map->matrix[0]);
		free(map->matrix);
	}
	if (map->map_colours)
		free(map->map_colours);
	if (map_read)
		freesplit(map_read);
	if (is_perror)
		perror(message);
	else
		write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	error_exit_vars(t_vars *vars, char *message, int is_perror)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	error_exit(&vars->map, message, is_perror, NULL);
}
