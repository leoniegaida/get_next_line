#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (static_buff == NULL)
	{
		static_buff = malloc(1);
		if (!static_buff)
			return (NULL);
		static_buff[0] = '\0';
	}
	return (read_from_fd(fd, &static_buff));
}

char	*read_from_fd(int fd, char **static_buff)
{
	char	*sized_buff;
	int		bytes_read;

	while (!char_in_str('\n', *static_buff))
	{
		sized_buff = malloc(BUFFER_SIZE + 1);
		if (!sized_buff)
			return (null_and_free(sized_buff, static_buff));
		bytes_read = read(fd, sized_buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (null_and_free(sized_buff, static_buff));
		if (!bytes_read)
			break ;
		sized_buff[bytes_read] = '\0';
		*static_buff = realloc_and_join(*static_buff, sized_buff);
		if (!static_buff)
			return (null_and_free(sized_buff, static_buff));
	}
	return (extract_line(static_buff));
}

char	*extract_line(char **static_buff)
{
	int		pos;
	char	*temp;
	char	*result;

	if (*static_buff[0] == '\0')
		return (null_and_free(NULL, static_buff));
	pos = char_in_str('\n', *static_buff);
	if (pos == -1)
	{
		result = realloc_and_join(*static_buff, "");
		null_and_free(NULL, static_buff);
		return (result);
	}
	result = ft_substr(*static_buff, 0, pos);
	temp = *static_buff;
	*static_buff = ft_substr(*static_buff, pos + 1, ft_strlen(*static_buff) - 1);
	free (temp);
	if (result == NULL || *static_buff == NULL)
		return (null_and_free(result, static_buff));
	return (result);
}