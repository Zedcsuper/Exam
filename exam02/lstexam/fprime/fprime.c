#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;


	i = 2;
	if (ac == 2)
	{
		int x = atoi(av[1]);
		if (x == 1)
			printf("1");	
		while (i <= x)
		{
			if (x % i == 0)
			{	
				printf("%d", i);
				if (x != i)
					printf("*");
				x /= i;
				i--;
			}
			i++;
		}
	}
	printf("\n");
}
