#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	main(void)
{
	int arr[] = {3, 2, 1};
	sort_int_tab(arr, 3);
	int i = 0;
	while (i < 3)
		printf("%d\n", arr[i++]);
	return (0);
} 
