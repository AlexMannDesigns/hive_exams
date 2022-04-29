#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

void	print_arr(int *arr, unsigned int size)
{
	for (unsigned i = 0 ; i < size; i++)
		printf("%d\n", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[20] = {5, 2, 3, 4, 1, 0, 12, 2, 4, 3, 1, 1, 1, 27, -3, 500, 2, 4, 5, 0};
	unsigned int size = 20;	

	printf("ORIG:\n");
	print_arr(arr, size);
	sort_int_tab(arr, size);
	printf("\nSORTED:\n");
	print_arr(arr, size);
	return (0);
}
