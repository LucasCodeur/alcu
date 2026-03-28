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
  if (size < 0)
  {
    ft_putstr_fd("ERROR", 2);
    return (1);
  }

  fd = open(argv[1], O_RDONLY);
  int* lines = fill_array(fd, size);
  if (!lines)
    return (1);

  // for (int i = 0; i < size; i++)
  // {
  //   printf("lines[i] : %d\n", lines[i]);
  // }

  // int player = 1;
  for (int i = size - 1; i >= 0; i--)
  {
    while (lines[i] != 0)
    {
      char buffer[100] = "";
      // ft_putstr_fd("Player : ", 1);
      // char* choice = ft_itoa(i % 2 == 0 ? 1 : 2);
      // ft_putstr_fd(choice, 1);
      // ft_putstr_fd("\n", 1);
      ft_putstr_fd("Please choose between 1 and 3 items\n", 1);
      print_board(lines, size);
      int	nb_read = read(0, buffer, sizeof(buffer));
      char* temp = NULL;
      if (nb_read > 0)
      {
	int choice = ft_atoi(buffer);
	// temp = ft_itoa(choice);
	// ft_putstr_fd(temp, 1);
	if (choice > 0 && choice < 4)
	{
	 if (choice > lines[i])
	 {
	    ft_putstr_fd("-", 1);
	    ft_putstr_fd("\n", 1);
	    ft_putstr_fd("Invalid choice\n", 1);
	    i++;
	    free(temp);
	    continue ;
	 }
	  lines[i] -= choice; 
	}
	else
	{
	  ft_putstr_fd("-", 1);
	  ft_putstr_fd("\n", 1);
	  ft_putstr_fd("Invalid choice\n", 1);
	  i++;
	  free(temp);
	  continue ;
	}
      }
    }
  }
  close(fd);
  free(lines);
  return (0);
}
