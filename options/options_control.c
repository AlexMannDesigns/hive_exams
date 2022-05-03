#include "options.h"

void	print_bits(unsigned int nb)
{
	int i = (sizeof(nb) * 8) - 1;
	int j = 0;	

	while (i >= 0)
	{
		nb & (1U << i) ? write(1, "1", 1) : write(1, "0", 1);
		i--;
		j++;
		if (j % 8 == 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	options_control(char **av)
{
	int i, j;
	unsigned int res;

	i = res = 0;
	while (av[i])
	{
		j = 1;
		while (av[i][j])
		{
			res |= (1U << (av[i][j] - 97));
			j++;
		}
		i++;
	}
	print_bits(res);
}
