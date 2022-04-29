/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdlib.h>

static unsigned int	is_ws(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

static size_t	word_count(char *str)
{
	size_t count, i;
	
	count = i = 0;
	while (str[i])
	{
		if (!is_ws(str[i]))
		{
			count++;
			while (!is_ws(str[i + 1]))
				i++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_substrlen(char *str, size_t i)
{
	size_t len;
	
	len = 0;
	while (!is_ws(str[i]))
	{
		len++;
		i++;
	}
	return (len);
}

static char	*copy_word(char *str, size_t i, size_t len)
{
	char *res;
	size_t j;	

	res = (char *) malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	j = 0;
	while (j < len)
	{
		res[j] = str[i];
		j++;
		i++;
	}
	return (res);
}

char	**ft_split(char *str)
{
	char **arr;
	size_t wc, len, i, j;

	wc = word_count(str);	
	arr = (char **) malloc(sizeof(char *) * (wc + 1));
	arr[wc] = NULL;
	if (!wc)
		return (arr);
	j = i = 0;
	while (str[i])
	{
		if (!is_ws(str[i]))
		{
			len = ft_substrlen(str, i);
			arr[j] = copy_word(str, i, len);
			i += len;
			j++;
		}
		else
			i++;
	}
	return (arr);
}

