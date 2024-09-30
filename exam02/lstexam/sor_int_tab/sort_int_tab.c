#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_selection_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int		min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		if (min != i)
			swap(&tab[i], &tab[min]);
		i++;
	}
}

void	sort_int_tab(int *tab, unsigned int size)//bubble sort
{
	unsigned int	i;
	unsigned int	j;
	int		flag;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		flag = 0;
		while (j < size - i -1)
		{
			if (tab[j] > tab[j + 1])
			{
				swap(&tab[j], &tab[j + 1]);
				flag = 1;
			}
			j++;
		}
		if (!flag)
			break;
		i++;
	}
}

int	main()
{
	int ar[5] = {5,4,2,3,1};
	sort_int_tab(ar, 5);
	int i = 0;
	while (i < 5)
		printf("%d ", ar[i++]);
	printf("\n");
	int ar2[5] = {5,4,2,3,1};
	sort_selection_tab(ar2, 5);
	i = 0;
	while (i < 5)
		printf("%d ", ar2[i++]);
	printf("\n");
	return (0);
}
