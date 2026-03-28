/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:30:29 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 20:54:09 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "alcu.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	check_char_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && i < 100)
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
			return (0);
	return (1);
}

void	player_turn(int *line)
{
	char	*temp;
	int		choice;

	while (1)
	{
		ft_putstr_fd("\nPlease choose between 1 and 3 items\n", 1);
		temp = get_next_line(0);
		if (temp && ft_strlen(temp) > 0)
		{
			if (!check_char_int(temp))
			{
				free(temp);
				continue ;
			}
			choice = ft_atoi(temp);
			free(temp);
			if (choice > 0 && choice < 4)
			{
				if (choice > *line)
				{
					ft_putstr_fd("-\nInvalid choice\n", 1);
					continue ;
				}
				*line -= choice;
				break ;
			}
			else
			{
				ft_putstr_fd("-\nInvalid choice\n", 1);
				continue ;
			}
		}
	}
}

void	game(int *lines, int size)
{
	int	ai_turn;
	int	choice;

	ai_turn = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		while (lines[i] != 0)
		{
			ft_putstr_fd("\n------------------------------\n", 1);
			if (!ai_turn)
			{
				print_board(lines, size);
				player_turn(&lines[i]);
			}
			else
			{
				print_board(lines, size);
				ft_putstr_fd("\n", 1);
				choice = ai(lines, size);
				ft_putstr_fd("AI play ", 1);
				ft_putnbr_fd(choice, 1);
				ft_putstr_fd("\n", 1);
				lines[i] -= choice;
			}
			ai_turn = ai_turn == 0;
		}
	}
	if (!ai_turn)
		ft_putstr_fd("AI win ! It will replace you\n", 1);
	else
		ft_putstr_fd("You win ! Well done\n", 1);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	size;
	int	*lines;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	size = check_input(fd);
	if (size < 0)
	{
		ft_putstr_fd("ERROR", 2);
		return (1);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	lines = fill_array(fd, size);
	if (!lines)
		return (1);
	// for (int i = 0; i < size; i++)
	// {
	//   printf("lines[i] : %d\n", lines[i]);
	// }
	// int player = 1;
	game(lines, size);
	close(fd);
	free(lines);
	return (0);
}
