#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

int	*ft_range(int start, int end)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * (ft_abs(start - end) + 1));
	
	while (start < end)
	{
		arr[i] = start;
		i++;
		start++;
	}
	arr[i] = start;
	while (start > end)
	{
		arr[i] = start;
		i++;
		start--;
	}
	arr[i] = start;
	return (arr);
}

int	main()
{
	int start = 0;
	int end = -3;
	int *ar = ft_range(start, end);
	int i = 0;
	while (i < ft_abs(start - end) + 1)
		printf("%d ", ar[i++]);
	return (0);
}



