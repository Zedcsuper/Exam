#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_rrange(int start, int end)
{
	int	*arr;
	int	i;
	int	size;
	
	size = ft_abs(end - start) + 1;
	i = 0;
	arr = malloc(sizeof(int) * (ft_abs(start - end) + 1));
	if(!arr)
		return (NULL);
	if (start <= end)
	{
		while (end >= start)
		{
			arr[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		while (end <= start)
		{
			arr[i] = end;
			i++;
			end++;
		}
	}
	return (arr);
}

int	main()
{
	int *ar = ft_rrange(2, -1);
	int i = 0;
	while (i < ft_abs(4))
	{
		printf("%d ", ar[i]);
		i++;
	}
	printf("\n");
	return (0);
}
