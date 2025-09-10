#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// main function
char	*get_next_line(int fd);

// parts of main function
char	*read_from_fd(int fd, char **static_buf);
char	*extract_line(char **static_buf);
char	*prepare_for_next_call(char **static_buf);

// helper functions
int		char_in_str(char c, char *str);
char    *realloc_and_join(char *str1, char *str2);
void	copy(char *src, char *dest);

#endif