#include <stdlib.h>
#include <stdio.h>
typedef struct	s_list t_list;

struct	s_list
{
	int	data;
	t_list	*next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
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

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*create_node(int data)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);

	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_back(t_list **head, int data)
{
	t_list *new_node = create_node(data);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	t_list *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list *list = NULL;

	push_back(&list, 3);
	push_back(&list, 4);
	push_back(&list, 1);
	push_back(&list, 1);
	push_back(&list, 7);
	push_back(&list, 8);
	push_back(&list, 9);
	push_back(&list, 11);
	printf("orginal list: ");
	print_list(list);
	list = sort_list(list, ascending);
	printf("sorted list: ");
	print_list(list);
	t_list *temp;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
