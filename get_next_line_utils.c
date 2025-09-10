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

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char    *realloc_and_join(char *str1, char *str2)
{
    char    *result;
    int     i;
    int     j;

    result = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (str1[i])
    {
        result[i] = str1[i];
        i++;
    }
    free(str1);
    j = 0;
    while (str2[j])
    {
        result[i] = str2[j];
        i++;
        j++;
    }
	free (str2);
    result[i] = '\0';
    return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_substr(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(end - start + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}