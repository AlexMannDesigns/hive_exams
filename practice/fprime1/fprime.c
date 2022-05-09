#include <stdlib.h>
#include <stdio.h>

int		is_prime(int nb)
{
	int i = 3;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;	
	}
	return (1);
}

void	fprime(int nb)
{
	int i, first;

	if (nb == 1)
	{
		printf("1");
		return ;	
	}
	first = 1;
	i = 2;
	while ((nb / i) >= 1)
	{
		if (nb % i == 0 && is_prime(i))
		{
			if (first)
				printf("%d", i);
			else
				printf("*%d", i);
			first = 0;
			nb /= i;
		}
		else
			i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(atoi(av[1]));	
	}
	printf("\n");
	printf("10 %% 16 = %d\n", 10 % 16);

	return (0);
}
