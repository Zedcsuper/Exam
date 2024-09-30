#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

int	main()
{
	t_list *head, *sec , *third;
	head = (t_list *)malloc(sizeof(t_list));
	sec = (t_list *)malloc(sizeof(t_list));
	third = (t_list *)malloc(sizeof(t_list));
	head->data = "abc";
	head->next = sec;
	sec->data = "efg";
	sec->next = third;
	third->data = "higklmn";
	third->next = NULL;
	printf("%d\n", ft_list_size(head));
	return (0);
}
