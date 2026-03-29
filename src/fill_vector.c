/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:21:46 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/29 16:31:19 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include "get_next_line.h"

#include "alcu.h"

bool fill_vector(t_vector* lines, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		lines->pfVectorAdd(lines, line);
		line = get_next_line(fd);
	}
	return (true);
}

int*	fill_array(t_vector* lines, int* size)
{
	int*	res;
	int		i;
	char*	line;

	i = 0;
	line = NULL;
	*size = lines->pfVectorTotal(lines);
	res = malloc(sizeof(int) * *size);
	if (!res)
		return (NULL);
	while (i < *size)
	{
		line = (char*)lines->pfVectorGet(lines, i);
		res[i] = ft_atoi(line);
		i++;
	}
	return (res);
}
