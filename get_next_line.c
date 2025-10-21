/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:23:58 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/21 21:16:01 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			panic_button;

	panic_button = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("", &panic_button);
	read_from_fd(fd, &stash, &panic_button);
	extract_line(&stash, &line, &panic_button);
	if (panic_button == 1 || !line || !line[0])
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	else
		return (line);
}

void	read_from_fd(int fd, char **stash, int *panic_button)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		*panic_button = 1;
		return ;
	}
	//bytes_read = 1;
	while (ft_strchr(*stash, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
		{
			if (bytes_read < 0)
				*panic_button = 1;
			break ;
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer, panic_button);
		free (*stash);
		*stash = temp;
	}
	free(buffer);
}

void	extract_line(char **stash, char **line, int *panic_button)
{
	char	*temp;

	if (ft_strchr(*stash, '\n') >= 0)
	{
		*line = ft_substr(*stash, 0, '\n', panic_button);
		temp = ft_substr(*stash, '\n', '\0', panic_button);
		free(*stash);
		*stash = temp;
	}
	else
	{
		*line = ft_strdup(*stash, panic_button);
		free(*stash);
		*stash = ft_strdup("", panic_button);
	}
}
