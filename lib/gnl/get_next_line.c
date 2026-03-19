/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:25:19 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/06 14:25:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s2)
		return (s1);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new = gnl_minijoin(s1, s2);
	return (new);
}

static int	read_file(char **stash, char *buffer, int fd)
{
	int	bytes;

	bytes = 1;
	while (gnl_strchr_i(*stash, '\n') == -1 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (*stash)
			{
				free(*stash);
				stash = NULL;
			}
			return (-2);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		*stash = gnl_strjoin(*stash, buffer);
		if (!*stash)
			return (-2);
	}
	return (gnl_strchr_i(*stash, '\n'));
}

static char	*eof(char **stash)
{
	char	*line;

	line = *stash;
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = read_file(&stash, buffer, fd);
	free(buffer);
	if (i == -2)
		return (NULL);
	if (i >= 0)
	{
		line = gnl_extract(stash, i);
		stash = gnl_substr(stash, i + 1);
		return (line);
	}
	if (stash && stash[0] != '\0')
		return (eof(&stash));
	return (NULL);
}
