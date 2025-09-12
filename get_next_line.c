#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");													// stash = malloc
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_from_fd(fd, &buffer, &stash);											// temp = malloc(stash+buffer), free (stash), stash = temp
	free(buffer);
	line = ft_strdup("");
	remainder = ft_strdup("");
	extract_line(stash, &line, &remainder);
	free(stash);																// free(stash) DOUBLE FREE HERE AND
	if (remainder[0])
		stash = remainder;
	else
		free(remainder);
	if (line[0])
		return (line);
	else
	{
		free(line);
		return (NULL);
	}
}

void	read_from_fd(int fd, char **buffer, char **stash)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (ft_strchr(*stash, '\n') < 0 && bytes_read > 0)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temp = ft_strjoin(*stash, *buffer);
		free (*stash);															// DOUBLE FREE AND HERE
		*stash = temp;
	}
}

void	extract_line(char *stash, char **line, char **remainder)
{
	char	*temp;

	if (ft_strchr(stash, '\n') >= 0)
	{
		temp = ft_substr(stash, '\0', '\n');
		free(*line);
		*line = temp;
		temp = ft_substr(stash, '\n', '\0');
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		temp = ft_strdup(stash);
		free(*line);
		*line = temp;
	}
}
