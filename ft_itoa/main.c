#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr);

int	main(void) 
{
	char *str;

	str = ft_itoa(12);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(1);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(-77);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(2147483647);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(0);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(123);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(99999999);
	printf("%s\n", str);
	free(str);
	str = ft_itoa(-12-3);
	printf("%s\n", str);
	free(str);
	return (0);
}
