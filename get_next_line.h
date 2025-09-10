#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*read_from_fd(int fd, char **static_buff);
char	*extract_line(char **static_buff);
char	*null_and_free(char *p1, char **p2);
int		char_in_str(char c, char *str);
char    *realloc_and_join(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_substr(char *str, int start, int end);

#endif