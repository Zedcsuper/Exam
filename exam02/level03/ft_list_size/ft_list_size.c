#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list *list;
	int	i;

	list = begin_list;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	insert_beginning(t_list **root, int value)
{
	t_list *new_node;
	new_node = malloc(sizeof(t_list));
	int *ptr = (int *)malloc(sizeof(int));
	*ptr = value;
	if (!new_node)
		exit(1);
	new_node->data = ptr;
	new_node->next = *root;
	*root = new_node;
}

int	main()
{
	t_list *root;
	root = NULL;
	insert_beginning(&root, 5);
	insert_beginning(&root, 4);
	insert_beginning(&root, 3);
	insert_beginning(&root, 2);
	t_list *curr = root;
	while (curr)
	{
		printf("%d ",*(int *)curr->data);
		curr = curr->next;
	}
	printf("\n");
	int x = ft_list_size(root);
	printf("%d\n", x);
	return (0);
}
