#ifndef LIST_H
#define LIST_H

int	ascending(int a, int b);

typedef struct s_list
{
	int	data;
	struct	s_list	*next;
}				t_list;

#endif
