/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 06:23:45 by lgaida            #+#    #+#             */
/*   Updated: 2025/09/15 20:50:36 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_strdup(char *str, int *panic_button)
{
	int		str_len;
	int		i;
	char	*dest;

	if (!str)
		return (NULL);
	str_len = ft_strchr(str, '\0');
	dest = malloc(str_len + 1);
	if (!dest)
	{
		*panic_button = 1;
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	if (c == '\0')
	{
		return (i);
	}
	return (-1);
}

char	*ft_strjoin(char *str1, char *str2, int *panic_button)
{
	int		str1_len;
	int		str2_len;
	char	*str;

	str1_len = ft_strchr(str1, '\0');
	str2_len = ft_strchr(str2, '\0');
	str = malloc(str1_len + str2_len + 1);
	if (!str)
	{
		*panic_button = 1;
		return (NULL);
	}
	ft_memcpy(str, str1, str1_len);
	ft_memcpy(&str[str1_len], str2, str2_len);
	str[str1_len + str2_len] = '\0';
	return (str);
}

char	*ft_memcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char *str, char start, char end, int *panic_button)
{
	char	*substr;
	int		i_start;
	int		i_end;
	int		substr_len;

	if (start)
		i_start = ft_strchr(str, start) + 1;
	else
		i_start = 0;
	if (end)
		i_end = ft_strchr(str, end) + 1;
	else
		i_end = ft_strchr(str, end);
	substr_len = i_end - i_start;
	substr = malloc(substr_len + 1);
	if (!substr)
	{
		*panic_button = 1;
		return (NULL);
	}
	ft_memcpy(substr, &str[i_start], substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
