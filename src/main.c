/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:30:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 16:06:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "../libft/libft.h"
#include "alcu.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }

  int fd = open(argv[1], O_RDONLY);

  if (fd == -1)
  {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }

  int size = check_input(fd);
  printf("size %d\n", size);
  if (size < 0)
  {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }
  if (size < 0)
  {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }
  int* lines = fill_array(fd, size);
  if (!lines)
    return (1);
  for (int i = 0; i < size; i++)
  {
    char buffer[100] = "";
    ft_putstr_fd("Player : ", 1);
    char* temp = ft_itoa(i % 2 == 0 ? 1 : 2);
    ft_putstr_fd(temp, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("Enter the number of matchs to take off: ", 1);
    int	nb_read = read(0, buffer, sizeof(buffer));
    if (nb_read > 0)
    {
      int temp = ft_atoi(buffer); 
      if (temp > 1 && temp < 4)
	lines[i] -= temp; 
      else
	ft_putstr_fd("Between 1 and 3", fd);
      print_board(lines, 5);
    }
  }
  close(fd);
  return (0);
}
