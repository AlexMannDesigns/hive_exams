#include <stdio.h>

char	**ft_split(char *str);

int main(void)
{
	char **arr;

	char *str = "hello\t world\n";
	arr = ft_split(str);
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;	
	}	
	return (0);
}
