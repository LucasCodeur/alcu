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

static int get_fd(int argc, char **argv) {
  if (argc == 2) {
    return (open(argv[1], O_RDONLY));
  } else if (argc == 1)
    return (0);
  else
    return (-1);
}

int main(int argc, char *argv[]) {

  int fd;
  int size;
  int *lines_int;
  t_vector lines;

  if (vector_init(&lines) == false) {
    ft_putstr_fd("ERROR\n", 2);
    return (1);
  }
  fd = get_fd(argc, argv);
  lines_int = NULL;
  size = 0;
  if (fd < 0 || fill_vector(&lines, fd) == false) {
    lines.pfVectorFree(&lines);
    ft_putstr_fd("ERROR\n", 2);
    return (1);
  }
  if (check_input(&lines) == false) {
    lines.pfVectorFree(&lines);
    ft_putstr_fd("ERROR\n", 2);
    return (1);
  }
  lines_int = fill_array(&lines, &size);
  lines.pfVectorFree(&lines);
  if (!lines_int) {
    lines.pfVectorFree(&lines);
    ft_putstr_fd("ERROR\n", 2);
    return (1);
  }
  close(fd);
  if (open("/dev/tty", O_RDONLY) < 0 || game(lines_int, size) == false) {
    free(lines_int);
    ft_putstr_fd("ERROR\n", 2);
    return (1);
  }
  if (fd != 0)
    close(fd);
  free(lines_int);
  return (0);
}
