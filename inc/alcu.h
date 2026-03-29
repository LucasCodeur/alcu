/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:27:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/29 14:58:00 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

#include "vector.h"

#include <stddef.h>
#include <stdbool.h>

char		*read_file(int fd);
bool		check_input(t_vector* lines);
void		print_board(int *game_state, size_t nb_line);
bool 		fill_vector(t_vector* lines, int fd);
int		ai(int *gamestate, int nb_line);
void		game(int *lines, int size);
int*		fill_array(t_vector* lines, int* size);

#endif
