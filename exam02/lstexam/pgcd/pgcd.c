#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int	i;
	int	pg;

	pg = 0;
	i = 1;
	while (i < a && i < b)
	{
		if (a % i == 0 && b % i == 0)
			pg = i;
		i++;
	}
	return (pg);
}

int	main(int ac, char **av)
{

	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
