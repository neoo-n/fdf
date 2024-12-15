/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:30 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/15 17:43:06 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_ptrstr(char **strptr)
{
	int	i;
	i = 0;
	if (!strptr)
		return ;
	while (strptr[i])
	{
		free(strptr[i]);
		i++;
	}
	free(strptr);
}

void	error_exit(int fd, char **map, char *message)
{
	if (fd > -1)
		close (fd);
	if (map)
		free_ptrstr(map);
	perror(message);
	exit(EXIT_FAILURE);
}