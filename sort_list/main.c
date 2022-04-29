#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

t_list	*create_list(int size)
{
	t_list *lst;
	t_list *head;
	
	lst = (t_list *) malloc(sizeof(t_list));
	head = lst;
	lst->data = size;
	lst->next = NULL;
	while (--size)
	{
		lst->next = (t_list *) malloc(sizeof(t_list));
		if (size % 3 == 0)
			lst->next->data = 12;
		else
			lst->next->data = size;
		lst = lst->next;
	}	
	return (head);
}

int	descending(int a, int b)
{
	return (a >= b);
}

int	ascending(int a, int b)
{
	return (a <= b);
}

int main(void)
{
	t_list	*lst;
	int	size;

	size = 100;
	lst = create_list(size);
	printf("orig:\n");
	print_list(lst);
	sort_list(lst, ascending);
	printf("\nsorted:\n");
	print_list(lst);
	sort_list(lst, descending);
	printf("\nsorted:\n");
	print_list(lst);
	return (0);
}
