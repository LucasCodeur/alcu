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

#include "../libft/libft.h"
#include "get_next_line.h"

// char *str_append(char *str, char *to_append) {
//   char *new_str;
//   int i;
//   int j;
//
//   if (!str)
//     return to_append;
//   new_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(to_append) + 1));
//   if (!new_str)
//     return NULL;
//   i = -1;
//   while (str[++i])
//     new_str[i] = str[i];
//   j = -1;
//   while (to_append[++j])
//     new_str[i + j] = to_append[j];
//   new_str[i + j] = '\0';
//   free(str);
//   return (new_str);
// }
//
// char *read_file(int fd) {
//   char *buf;
//   int char_readed;
//   char *content;
//
//   content = NULL;
//   buf = malloc(sizeof(char) * 2);
//   if (!buf)
//     return (NULL);
//   buf[1] = '\0';
//   char_readed = read(fd, buf, 1);
//   while (char_readed > 0) {
//     str_append(content, buf);
//     char_readed = read(fd, buf, 1);
//   }
//   free(buf);
//   return (content);
// }
//

void free_split(char **tab) {
  int i;

  i = 0;
  while (tab[i]) {
    free(tab[i]);
    i++;
  }
  free(tab);
}

int check_input(int fd) 
{
	char **content;
	int i;
	int j;
	char * line  = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
			
	}
	content = ft_split(get_next_line(fd), '\n');
	if (!content)
		return (-2);
	i = -1;
	while (content[++i]) 
	{
		j = -1;
		while (content[i][++j]) 
		{
			if (content[i][j] <= '0' && content[i][j] >= '9')
			{
				free_split(content);
				return (-1);
			}
		}
	}
	free_split(content);
	return (i);
}
