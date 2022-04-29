#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

t_list	*list_constructor(int i)
{
	t_list *lst;
	t_list *head;
	char *arr[6];
	
	arr[0] = "hello";
	arr[1] = "world";
	arr[2] = "my";
	arr[3] = "name";
	arr[4] = "is";
	arr[5] = "alex";

	lst = (t_list *) malloc(sizeof(t_list));
	lst->data = (void *) strdup("hello"); 
	lst->next = NULL;
	head = lst;
	int j = 1;
	while (i)
	{
		lst->next = (t_list *) malloc(sizeof(t_list));
		lst->next->data = (void *) strdup(arr[j]); 
		lst = lst->next;
		i--;
		j++;
	}
	lst->next = NULL;
	return (head);
}

void print_list(t_list *lst)
{
	char *str;
	while (lst)
	{
		str = (char *)(lst->data);
		printf("%s\n", str);
		lst = lst->next;
	}
}

void	str_toupper(void *str)
{
	int i = 0;
	char *temp;

	temp = (char *) str;
	while (temp[i])
	{
		temp[i] = toupper(temp[i]);
		i++;	
	}
}

int main(void)
{
	t_list *lst;
	int i = 5;

	//construct list
	lst = list_constructor(i);
	//print list
	print_list(lst);
	//apply function pointer
	ft_list_foreach(lst, str_toupper);
	//print list again
	print_list(lst);
	return (0);
}
