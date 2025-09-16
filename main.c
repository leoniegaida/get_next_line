/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:44:45 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/16 12:56:04 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define FILE "file.txt"

int	main(void)
{
	int		fd;
	int		lines;
	char	*line;
	
	fd = open(FILE, O_RDONLY);
	lines = 1;
	while ((line = get_next_line(fd)))
	{
		printf("%d -> %s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}
