/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:30 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/17 11:41:17 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit_perror(int fd, t_map map, char *message)
{
	if (fd > -1)
		close(fd);
	if (map.map_read)
		freesplit(map.map_read);
	perror(message);
	exit(EXIT_FAILURE);
}

void	error_exit_write(int fd, t_map map, char *message)
{
	if (fd > -1)
		close(fd);
	if (map.map_read)
		freesplit(map.map_read);
	if (map.map_tab)
		freeatoi(map.map_tab, map.y_len);
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}