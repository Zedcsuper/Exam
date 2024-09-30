#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
	t_list	*current;
	t_list	*previous;
	t_list	*to_free;

	previous = 0;
	current = *begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			to_free = current;
			if (previous == 0)
				*begin_list = current->next;
			else
				previous->next = current->next;
			current = current->next;
			free(to_free);
		}
		else
		{
			previous = current;
			current = current->next;
		}
		
	}
}

void	ft_printlist(t_list *lst)
{
	while(lst)
	{
		printf("data :%d\n", *(int*)lst->data);
		lst= lst->next;
	}
}

t_list	*lst_new(void	*data)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->next = 0;
	lst->data = data;
	return (lst);
}

int	cmp(void *a, void *b)
{
	if (*(int*)a == *(int*)b)
		return (0);
	else
		return (1);
}
int	main(void)
{
	t_list	*lst;
	int a = 5;
	int b = 3;
	int x = 3;
	int c = 7;
	lst = lst_new(&a);
	lst->next = lst_new(&b);
	lst->next->next = lst_new(&x);
	lst->next->next->next = lst_new(&c);
	ft_printlist(lst);
	ft_list_remove_if(&lst, &b, &cmp);
	ft_list_remove_if(&lst, &x, &cmp);
	printf("-----------------------------\n");
	ft_printlist(lst);
	return (0);
}
