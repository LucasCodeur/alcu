/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:14:00 by dgaillet          #+#    #+#             */
/*   Updated: 2026/03/28 21:41:04 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "alcu.h"
#include "get_next_line.h"

static int check_char_int(char *str) {
  int i;

  i = -1;
  while (str[++i] && i < 100)
    if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
      return (0);
  return (1);
}

static int play_choice(int *line, int choice) {
  if (choice > 0 && choice < 4) {
    if (choice > *line) {
      ft_putstr_fd("-\nInvalid choice\n", 1);
      return (0);
    }
    *line -= choice;
    return (1);
  } else {
    ft_putstr_fd("-\nInvalid choice\n", 1);
    return (0);
  }
}

static bool player_turn(int *line) {
  char *temp;
  int choice;

  while (1) {
    ft_putstr_fd("\nPlease choose between 1 and 3 items\n", 1);
    temp = get_next_line(0);
    if (!temp)
      return (false);
    if (temp && ft_strlen(temp) > 0) {
      if (!check_char_int(temp)) {
        free(temp);
        continue;
      }
      choice = ft_atoi(temp);
      if (play_choice(line, choice))
        break;
    } else
      ft_putstr_fd("-\nInvalid choice\n", 1);
    if (temp)
      free(temp);
  }
  if (temp)
    free(temp);
  return (true);
}

static bool play_turns(int *lines, int i, int *ai_turn, int size) {
  int choice;

  while (lines[i] != 0) {
    ft_putstr_fd("\n------------------------------\n", 1);
    if (!*ai_turn) {
      print_board(lines, size);
      if (player_turn(&lines[i]) == false)
        return (false);
    } else {
      print_board(lines, size);
      ft_putstr_fd("\n", 1);
      choice = ai(lines, size);
      ft_putstr_fd("AI play ", 1);
      ft_putnbr_fd(choice, 1);
      ft_putstr_fd("\n", 1);
      lines[i] -= choice;
    }
    *ai_turn = *ai_turn == 0;
  }
  return (true);
}

bool game(int *lines, int size) {
  int ai_turn;
  int i;

  ai_turn = 1;
  i = size - 1;
  while (i >= 0) {
    if (play_turns(lines, i, &ai_turn, size) == false)
      return (false);
    i--;
  }
  if (!ai_turn)
    ft_putstr_fd("AI win ! It will replace you\n", 1);
  else
    ft_putstr_fd("You win ! Well done\n", 1);
  return (true);
}
