#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return (0);
	int bb = b;
	int aa = a;
	int tmp;
	while (bb != 0)
	{
		tmp = bb;
		bb = aa % bb;
		aa = tmp;
	} 

	return ((a * b) / aa);
}

int	main()
{
	printf("%d\n", lcm(6, 10));
	return (0);
} 
