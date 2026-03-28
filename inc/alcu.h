/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:27:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 15:26:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
#define ALCU_H

#include <stddef.h>

char *read_file(int fd);
int check_input(int fd);
void print_board(int *game_state, size_t nb_line);
int *fill_array(int fd, int size);
int ai(int *gamestate, int nb_line);

#endif
