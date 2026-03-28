/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:30:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 21:41:29 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "alcu.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_fd(int argc, char **argv)
{
	if (argc == 2)
	{
		return (open(argv[1], O_RDONLY));
	}
	else if (argc == 1)
		return (0);
	else
		return (-1);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	size;
	int	*lines;

	fd = get_fd(argc, argv);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	size = check_input(fd);
	if (size < 0)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	lines = fill_array(fd, size);
	if (!lines)
		return (1);
	game(lines, size);
	close(fd);
	free(lines);
	return (0);
}
