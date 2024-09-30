#include <stdio.h>
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main()
{
	int a = 1;
	int b = 5;
	ft_swap(&a, &b);
	printf("a %d  b %d", a, b);
	return (0);
}
