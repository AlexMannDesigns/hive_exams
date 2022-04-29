/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

/*
*	ALGO (bubble sort):
*	check value of 1st and 2nd el
*	if 1st > 2nd, swap them
*	if elements swapped, switch flag variable to true
*	then check 2nd & 3rd, etc...
*	after checking last 2 els, check flag variable
*	if flag variable is false, list is sorted
*/

void ft_swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i, swapped;

	i = swapped = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			swapped = 1;
		}		
		i++;
	}
	if (swapped)
		sort_int_tab(tab, size);
}
