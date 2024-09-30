#include <stdio.h>

int	lcm(unsigned int a, unsigned int b)
{
	int	i;
	int	hcf;
	int	lcm;

	i = 1;
	while (i <= a && i <= b)
	{
		if( a % i == 0 && b % i == 0)
			hcf = i;
		i++;
	}
		return ((a * b) / hcf);
}

int	main()
{
	printf("%d\n", lcm(6, 9));
	printf("%d\n", lcm(7, 13));
	printf("%d\n", lcm(12, 36));
	printf("%d\n", lcm(15,15));
	printf("%d\n", lcm(1,20));
	printf("%d\n", lcm(123456,789012));
	printf("%d\n", lcm(1,1));
	return (0);
}		
