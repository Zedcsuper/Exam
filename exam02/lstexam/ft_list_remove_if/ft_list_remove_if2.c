#include "ft_list.h"
#include "stdlib.h"
#include "stdio.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
	t_list	*cur;
	t_list	*prev;
	t_list	*to_free;

	prev = 0;
	cur = *begin_list;
	while (cur)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			to_free = cur;
			if (prev == 0)
				*begin_list = cur->next;
			else
				prev->next = cur->next;
			cur = cur->next;
			free(to_free);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void	ft_printlist(t_list *lst)
{
	while (lst)
	{
		printf("data :%d\n", *(int*)lst->data);
		lst = lst->next;
	}
}

t_list	*lst_new(void *data)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->next = 0;
	lst->data = data;
	return (lst);
}

int	cmp(void *a, void *b)
{
	if (*(int *)a == *(int *)b)
		return (0);
	else
		return (1);
}

int	main(void)
{
	t_list	*lst;
	int a = 1  , b = 2, c = 3, d = 4;
	lst = lst_new(&a);
	lst->next = lst_new(&b);
	lst->next->next = lst_new(&c);
	lst->next->next->next = lst_new(&d);
	ft_printlist(lst);
	ft_list_remove_if(&lst, &c, &cmp);
	printf("-------------\n");
	ft_printlist(lst);
	return (0);
}
































