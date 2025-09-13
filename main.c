/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:44:45 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/13 06:48:50 by lgaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
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
