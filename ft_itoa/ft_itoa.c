/* 
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
#include <stdlib.h>

static char	*zero()
{
	char	*res;

	res = (char *) malloc(sizeof(char) * 2);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static int	neg(size_t *sign, size_t *min, int x)
{
	*sign = 1;
	if (x == -2147483648)
	{
		x++;
		*min = 1;
	}
	return (x * -1);
}

static size_t	get_len(int x)
{
	size_t len = 0;

	while (x > 0)
	{
		x /= 10;
		len++;	
	}
	return (len);
}

static char	*add_sign(char *orig, size_t min, size_t len)
{
	char	*res;
	int	i;	

	if (min)
	{
		orig[9] = '8';
	}
	res = (char *) malloc((sizeof(char) * len) + 2);
	res[0] = '-'; 
	res[len + 1] = '\0';
	i = 0;
	while (orig[i])
	{
		res[i + 1] = orig[i];
		i++;
	}
	free(orig);
	return (res);
}

char	*ft_itoa(int nbr)
{
	char	*res;
	size_t	len, sign, min, i;
	int	x;

	x = nbr;
	len = sign = min = 0;
	if (nbr == 0)
		return (zero());
	if (x < 0)
		x = neg(&sign, &min, x);
	len = get_len(x);
	res = (char *) malloc((sizeof(char) * len) + 1);	
	res[len] = '\0';
	i = len;
	while (x)
	{
		i--;
		res[i] = (char) ((x % 10) + 48);
		x /= 10;
	}
	if (sign)
		res = add_sign(res, min, len);
	return (res);
}
