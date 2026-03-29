/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:01:37 by dgaillet          #+#    #+#             */
/*   Updated: 2026/03/28 20:52:29 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"
#include "vector.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool	check_input(t_vector* lines)
{
	int		i;
	int		j;
	char* line;

	j = 0;
	line = NULL;
	while (j < lines->pfVectorTotal(lines))
	{
		line = (char*)lines->pfVectorGet(lines, j);
		i = -1;
		while (line[++i])
			if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '\n')
				return (false);
		if (ft_atoi(line) < 1 || ft_atoi(line) > 10000)
			return (false);
		j++;
	}
	return (true);
}
