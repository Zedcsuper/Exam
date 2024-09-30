#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int pg;
	int i;

	i = 1;
	pg = 1;
	while (a > i && b > i)
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
	{
		int x = pgcd(atoi(av[1]), atoi(av[2]));
		printf("%d", x);
	}
	printf("\n");
}
