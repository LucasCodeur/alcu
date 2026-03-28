/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:22:33 by dgaillet          #+#    #+#             */
/*   Updated: 2026/03/28 20:51:49 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int	best_to_take(int prev_should_start, int line)
{
	int	best;

	if (prev_should_start)
		best = 2;
	else
		best = 1;
	while (best <= line - 4)
	{
		best += 4;
	}
	return (best);
}

static int	to_play(int prev_should_start, int line)
{
	int	goal;

	goal = best_to_take(prev_should_start, line);
	if (line - goal < 3)
	{
		return ((line - goal) + 1);
	}
	else
	{
		return (1);
	}
}

static int	should_start(int prev_should_start, int line)
{
	if (prev_should_start && line == 1)
		return (!prev_should_start);
	if (prev_should_start)
		return (line % 4 != 1);
	else
		return (line % 4 != 0);
}

int	ai(int *gamestate, int nb_line)
{
	int	prev_should_start;
	int	i;

	prev_should_start = 0;
	i = -1;
	while (++i < nb_line && gamestate[i] != 0)
	{
		if (i == nb_line - 1 || gamestate[i + 1] == 0)
		{
			if (gamestate[i] == 1)
				return (1);
			return (to_play(prev_should_start, gamestate[i]));
		}
		prev_should_start = should_start(prev_should_start, gamestate[i]);
	}
	return (1);
}
