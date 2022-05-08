#include "options.h"

static int	check_valid(char c)
{
	char *s = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

int	check_flags(char **av)
{
	int i, j;

	i = 0;
	while (av[i])
	{
		if (av[i][0] != '-' || av[i][1] == '\0')
			return (0);
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'h')
			{
				write(1, USAGE, 35);
				return (2);
			}
			else if (!check_valid(av[i][j]))
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}
