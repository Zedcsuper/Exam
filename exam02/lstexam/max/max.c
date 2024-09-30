#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	i;
	int	max;
	if (!tab || len == 0)
		return (0);
	max = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	main(void)
{
	int arr[5] = {1,3,2,5,4};
	int maxn = max(arr, 5);
	printf("max = %d\n", maxn);
	return (0);
}
