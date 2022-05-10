/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/
#include <stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i, j;
	unsigned char res = 0;

	i = (sizeof(octet) * 8) - 1;
	j = 0;
	while (i >= 0)
	{
		if (octet & (1U << i))
			res |= (1U << j);
		j++;
		i--;
	}
	return (res);
}

void	print_bits(unsigned char octet)
{
	int i = (sizeof(octet) * 8) - 1;

	while (i >= 0)
	{
		if (octet & (1U << i))
			printf("1 ");
		else
			printf("0 ");
		i--;
	}

}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		unsigned char a = (unsigned char) atoi(av[1]);
		printf("ORIGINAL:\n");
		print_bits(a);
		printf("\n");
		printf("REVERSED:\n");
		a = reverse_bits(a);
		print_bits(a);
	}
	printf("\n");
	return 0;

}
