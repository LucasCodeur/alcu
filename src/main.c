/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:30:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 15:07:41 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "../libft/libft.h"
#include "alcu.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }

  int fd = open(argv[1], O_RDONLY);

  if (fd == -1) {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }

  int size = check_input(fd);
  printf("size %d\n", size);
  if (size < 0) {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }
  return (0);
  close(fd);
}
