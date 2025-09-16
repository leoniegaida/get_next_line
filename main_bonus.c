/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:44:45 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/16 11:51:32 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		lines;
	char	*line;
	int		fd1;
	int 	fd2;
	int		fd3;
	
	lines = 1;
	line = "init";
		
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	int	fd1_done = 0;
	int	fd2_done = 0;
	int	fd3_done = 0;

	while (!fd1_done || !fd2_done || !fd3_done)
	{
		if (!fd1_done)
		{
			line = get_next_line(fd1);
			if (line)
			{
				printf("%d -> %s\n", lines++, line);
				free(line);
			}
			else
				fd1_done = 1;
		}
		if (!fd2_done)
		{
			line = get_next_line(fd2);
			if (line)
			{
				printf("%d -> %s\n", lines++, line);
				free(line);
			}
			else
				fd2_done = 1;
		}
		if (!fd3_done)
		{
			line = get_next_line(fd3);
			if (line)
			{
				printf("%d -> %s\n", lines++, line);
				free(line);
			}
			else
				fd3_done = 1;
		}
	}

	close(fd1);
	close(fd2);
	close(fd3);
			
	return (0);
}


