#include <stdio.h>
#include <stdlib.h>

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}			t_list;

#endif

void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list *new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*current;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return;
	if (!(*begin_list))
	{
		*begin_list = new_elem;
	}
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = new_elem;
	}
}

int	main(void)
{
	t_list *list = NULL;

	ft_list_push_back(&list, "a");
	ft_list_push_back(&list, "aa");
	ft_list_push_back(&list, "3");
	ft_list_push_back(&list, "4");
	ft_list_push_back(&list, "5");
	ft_list_push_back(&list, "6");
	///////////////////////////////
	ft_list_foreach(list, print_data);
/////////////////////////////////////////////////////////
	t_list	*tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return (0);
}
