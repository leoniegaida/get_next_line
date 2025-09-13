/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:23:58 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/13 06:24:38 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	read_from_fd(fd, &stash);
	if (!stash[0])
	{
		free(stash);
		return (NULL);
	}
	line = ft_strdup("");
	extract_line(&stash, &line);
	if (line[0])
		return (line);
	else
	{
		free(stash);
		return (NULL);
	}
}

void	read_from_fd(int fd, char **stash)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(*stash);
		return ;
	}
	bytes_read = 1;
	while (ft_strchr(*stash, '\n') < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		free (*stash);
		*stash = temp;
	}
	free(buffer);
}

void	extract_line(char **stash, char **line)
{
	char	*temp;

	if (ft_strchr(*stash, '\n') >= 0)
	{
		temp = ft_substr(*stash, '\0', '\n');
		free(*line);
		*line = temp;
		temp = ft_substr(*stash, '\n', '\0');
		free(*stash);
		*stash = temp;
	}
	else
	{
		temp = ft_strdup(*stash);
		free(*line);
		*line = temp;
		temp = ft_strdup("");
		free(*stash);
		*stash = temp;
	}
}
