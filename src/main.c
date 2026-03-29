/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:30:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/29 16:31:17 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "alcu.h"

#include <fcntl.h>
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
	int*	lines_int;
	VECTOR_INIT(lines);

	fd = get_fd(argc, argv);
	lines_int = NULL;
	size = 0;
	if (fd < 0)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	fill_vector(&lines, fd);
	if (check_input(&lines) == false)
	{
		lines.pfVectorFree(&lines);
		ft_putstr_fd("ERROR", 2);
		return (1);

	}
	lines_int = fill_array(&lines, &size);
	if (!lines_int)
	{
		lines.pfVectorFree(&lines);
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	game(lines_int, size);
	close(fd);
	free(lines_int);
	lines.pfVectorFree(&lines);
	return (0);
}
