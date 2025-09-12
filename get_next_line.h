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
void	read_from_fd(int fd, char **buffer, char **stash);
void	extract_line(char *stash, char **line, char **remainder);

// helper functions (utils)
char	*ft_strdup(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_memcpy(char *dest, char *src, int len);
char	*ft_substr(char *str, char start, char end);

#endif