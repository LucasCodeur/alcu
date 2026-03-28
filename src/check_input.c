/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:01:37 by dgaillet          #+#    #+#             */
/*   Updated: 2026/03/28 15:14:49 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "../inc/get_next_line.h"
#include "../libft/libft.h"

int check_input(int fd) {
  int i;
  int j;
  char *line = NULL;

  line = get_next_line(fd);
  j = 0;
  while (line != NULL) {
    i = -1;
    while (line[++i])
      if (!(line[i] >= '0' && line[i] <= '9') && line[i] != '\n')
        return (free(line), -1);
    if (ft_atoi(line) < 1 || ft_atoi(line) > 10000)
      return (free(line), -1);
    free(line);
    j++;
    line = get_next_line(fd);
  }
  return (j);
}
