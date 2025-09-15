/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:24:01 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/15 19:14:33 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// main function
char	*get_next_line(int fd);

// parts of main function
void	read_from_fd(int fd, char **stash, int *panic_button);
void	extract_line(char **stash, char **line, int *panic_button);

// helper functions (utils)
char	*ft_strdup(char *str, int *panic_button);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *str1, char *str2, int *panic_button);
char	*ft_memcpy(char *dest, char *src, int len);
char	*ft_substr(char *str, char start, char end, int *panic_button);

#endif
