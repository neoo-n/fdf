/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:53:12 by dvauthey          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:15 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	opening_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0400);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (0);
	else if (argc != 2)
	{
		write(1, "Too many arguments\n", 19);
		return (1);
	}
	fd = opening_file(argv[1]);
	ft_fdf(fd, argv[1]);
	return (0);
}
