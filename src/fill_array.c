/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:21:46 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 16:05:46 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int*	fill_array(int fd, int size)
{
	int* res = malloc(sizeof(int) * size);
	if (res == NULL)
		return (NULL);

	char*	line = get_next_line(fd);
	int	i = 0;

	while (line != NULL)
	{
		res[i] = ft_atoi(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}
