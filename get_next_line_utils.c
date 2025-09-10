#include "get_next_line.h"

char	*null_and_free(char *p1, char **p2)
{
	if (p1 != NULL)
		free(p1);
	if (*p2 != NULL)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}

int	char_in_str(char c, char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return(i);
	return (-1);
}

char    *realloc_and_join(char *str1, char *str2)
{
    char    *result;
	int		str1_len;
	int		str2_len;

    str1_len = char_in_str('\0', str1) - 1;
	str2_len = char_in_str('\0', str2) - 1;
	result = malloc(str1_len + str2_len + 1);
    if (!result)
		return (NULL);
	copy(str1, result);
    free(str1);
	copy(str2, &result[str1_len]);
	free (str2);
    result[str1_len + str2_len] = '\0';
    return (result);
}

void	copy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}
