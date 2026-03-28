/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:06:30 by dgaillet          #+#    #+#             */
/*   Updated: 2026/03/28 16:06:32 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stddef.h>
#include <unistd.h>

void print_board(int *game_state, size_t nb_line) {
  int size_of_first;
  size_t i;
  int j;

  i = -1;
  size_of_first = game_state[0];
  while (++i < nb_line) {
    j = -1;
    while (++j < size_of_first - game_state[i])
      write(1, " ", 1);
    j = -1;
    while (++j < game_state[i]) {
      write(1, "|", 1);
      if (j < game_state[i] - 1)
        write(1, " ", 1);
    }
    j = -1;
    while (++j < size_of_first - game_state[i])
      write(1, " ", 1);
    write(1, "\n", 1);
  }
}
