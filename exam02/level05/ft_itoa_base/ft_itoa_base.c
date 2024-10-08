#include <stdlib.h>
#include <stdio.h>
#define abs(a) (a < 0) ? -a : a
char *g_base = "0123456789ABCDEF";

char	*ft_itoa_base(int value, int base)
{
	int negative = (base == 10 && value < 10) ? 1 : 0;
	int size = (negative) ? 3 : 2;
	int temp = value;
	while (temp /=base)
		size++;
	char *res = malloc(sizeof(char) * size);
	res[--size] = '\0';
	res[--size] = g_base[abs(value % base)];
	while (value /= base)
		res[--size] = g_base[abs(value % base)];
	if (negative == 1)
		res[--size] = '-';
	return (res);
}

int	main(int ac, char **av)
{
	printf("%d = %s\n", atoi(av[1]), ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
