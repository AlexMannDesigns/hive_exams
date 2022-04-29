#include "ft_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

int	cmp(void *ptr1, void *ptr2)
{
	char *p1;
	char *p2;

	p1 = (char *) ptr1;
	p2 = (char *) ptr2;
	if (!strcmp(p1, p2))
		return (0);
	return (1);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}

}

void	create_list(t_list **lst)
{
	int i = 0;
	t_list *head;
	char *arr[6];

	arr[0] = "alex"; 
	arr[1] = "alex";
	arr[2] = "hello"; 
	arr[3] = "alex"; 
	arr[4] = "is"; 
	arr[5] = "alex"; 
	*lst = (t_list *) malloc(sizeof(t_list));
	head = *lst;
	while (i < 6)
	{
		(*lst)->data = (void *) strdup(arr[i]);
		(*lst)->next = NULL;
		if (i + 1 < 6)
		{
			(*lst)->next = (t_list *) malloc(sizeof(t_list));
			*lst = (*lst)->next;
		}
		i++;
	}
	*lst = head;
}

int main(void)
{
	t_list *lst;
	char	*data_ref;

	//set up data_ref
	data_ref = "alex";
	//create list
	lst = NULL;
	create_list(&lst);
	printf("orig list:\n");
	print_list(lst);
	ft_list_remove_if(&lst, (void *)data_ref, cmp);
	printf("\n(case:'%s') editted list:\n", data_ref);
	print_list(lst);
	return (0);
}
