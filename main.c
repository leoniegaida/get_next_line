#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}