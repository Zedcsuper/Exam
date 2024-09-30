#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	return ((n & (n - 1)) == 0);
}

int	main()
{
	printf("2   %d\n", is_power_of_2(2));
	printf("3   %d\n", is_power_of_2(3));
	printf("4   %d\n", is_power_of_2(4));
	printf("16  %d\n", is_power_of_2(16));
	printf("100 %d\n", is_power_of_2(100));
	return (0);
}
