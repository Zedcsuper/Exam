#include <stdio.h>
#include <stdlib.h>
int	isprime(int n)
{
	int	i;

	i = 2;
	if (n == 2)
		return (1);
	while (i < n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
void	fprime1(int nb)
{
	int	i;

	i = 2;
	if (nb == 1)
	{
		printf("1");
		return;
	}
	if (isprime(nb))
	{
		printf("1*%d", nb);
		return;
	}
	while (nb != 1)
	{
		if (nb % i == 0)
		{
			while (nb % i == 0)
			{
				printf("%d", i);
				if (nb != i)
					printf("*");
				nb = nb / i;
			}
		}
		i++;
	}
}

void	fprime(int nb)
{
	int	i;

	i = 2;
	if (nb == 1)
	{
		printf("1");
		return;
	}
	while (nb >= i)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb != i)
				printf("*");
			nb = nb / i;
			i--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	fprime1(atoi(av[1]));
	printf("\n");
	fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
