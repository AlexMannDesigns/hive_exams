#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int	main(void)
{
	printf("base 2: %s\n", ft_itoa_base(42, 2));
	printf("base 10: %s\n", ft_itoa_base(42, 10));
	printf("base 16: %s\n", ft_itoa_base(42, 16));
	printf("base 7, neg: %s\n", ft_itoa_base(-42, 7));
	printf("base 10, neg: %s\n", ft_itoa_base(-42, 10));
	printf("base 2: %s\n", ft_itoa_base(42521, 2));
	printf("base 10: %s\n", ft_itoa_base(42521, 10));
	printf("base 16: %s\n", ft_itoa_base(42521, 16));
	printf("base 7, neg: %s\n", ft_itoa_base(-42521, 7));
	printf("base 10, neg: %s\n", ft_itoa_base(-42521, 10));
	
	return (0);
}
