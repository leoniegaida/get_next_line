#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!static_buf)
	{
		static_buf = malloc(1);
		if (!static_buf)
			return (NULL);
		static_buf[0] = '\0';
	}
	static_buf = read_from_fd(fd, &static_buf);
	line = extract_line(&static_buf);
	static_buf = prepare_for_next_call(&static_buf);
	return (line);
}

char	*read_from_fd(int fd, char **static_buf)
{
	char	*sized_buf;

	while (char_in_str('\n', *static_buf) < 0)
	{
		sized_buf = malloc(BUFFER_SIZE + 1);
		if (!sized_buf)
			return (NULL);
		read(fd, sized_buf, BUFFER_SIZE);
		*static_buf = realloc_and_join(*static_buf, sized_buf);
	}
	return(*static_buf);
}

char	*extract_line(char **static_buf)
{
	char	*line;
	int		line_len;
	int		i;

	line_len = char_in_str('\n', *static_buf);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*static_buf[i] != '\n')
	{
		line[i] = *static_buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*prepare_for_next_call(char **static_buf)
{
	char	*new_static_buf;
	int		pos_nl;
	int		end;
	int		remnant_len;

	pos_nl = char_in_str('\n', *static_buf);
	end = char_in_str('\0', *static_buf);
	remnant_len = end - pos_nl;
	new_static_buf = malloc(remnant_len + 1);
	if (!new_static_buf)
		return (NULL);
	copy(&((*static_buf)[pos_nl + 1]), new_static_buf);
	free(*static_buf);
	return(new_static_buf);
}
