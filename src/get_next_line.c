/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:07:17 by lud-adam          #+#    #+#             */
/*   Updated: 2026/03/28 15:13:54 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

size_t	ft_strlen_with_c(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

size_t	detect_newline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	fill_line(char *line, char *c_remaining, char *src, size_t *index)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (c_remaining && c_remaining[i])
	{
		line[i] = c_remaining[i];
		i++;
	}
	while (src[j] && src[j] != '\n')
	{
		line[i + j] = src[j];
		src[j] = 0;
		j++;
	}
	if (src[j] == '\n')
		line[i + j] = '\n';
	*index = j;
}

char	*build_line(char *src, char *c_remaining, size_t *index)
{
	char	*line;
	size_t	size;
	size_t	is_jump;

	is_jump = detect_newline(src);
	size = ft_strlen_with_c(src, '\n') + ft_strlen_with_c(c_remaining, '\0') + is_jump + 1;
	line = ft_calloc(size, sizeof(char));
	if (!line)
	{
		free(c_remaining);
		return (NULL);
	}
	if (!src)
		return (NULL);
	fill_line(line, c_remaining, src, index);
	if (c_remaining)
		free(c_remaining);
	return (line);
}

static void	read_file(int fd, char *buffer, ssize_t *nb_read)
{
	*nb_read = read(fd, buffer, BUFFER_SIZE);
	if (*nb_read < 0)
		return ;
	buffer[*nb_read] = '\0';
}

static char	*get_the_line(int fd, char *buffer)
{
	char	*line;
	size_t	i;
	ssize_t	nb_read;

	i = 0;
	nb_read = 0;
	line = NULL;
	if (buffer[0] != '\0')
	{
		line = build_line(buffer, NULL, &i);
		if (!line)
			return (NULL);
		ft_memcpy(buffer + i + 1, buffer, ft_strlen_with_c(buffer + i, '\0'));
	}
	while (detect_newline(line) != 0)
	{
		read_file(fd, buffer, &nb_read);
		if (nb_read < 0)
			return (free(line), NULL);
		if (nb_read == 0)
			break ;
		line = build_line(buffer, line, &i);
		ft_memcpy(buffer + i + 1, buffer, ft_strlen_with_c(buffer + i, '\0'));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "";
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_the_line(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
}
