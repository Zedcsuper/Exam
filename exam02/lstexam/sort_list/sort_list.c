#include <stdlib.h>
#include "list.h"
#include <stdio.h>

int	ascending(int a, int b)
{
	return (a <= b);
}
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

int	main()
{
	t_list a = {400, NULL};
	t_list b = {2, &a};
	t_list c = {100, &b};
	t_list d = {99, &c};
	print_lst(&d);
	t_list *sorted = sort_list(&d, ascending);
	print_lst(sorted);
	return (0);
}
	


