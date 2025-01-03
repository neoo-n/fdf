/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:30 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/03 00:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fdf.h"

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
