#include <unistd.h>

void	print_bits(unsigned char octec)
{
	int	i;
	unsigned char val;

	val = 0;
	i = 7;
	while (i >= 0)
	{
		val = (octec >> i) & 1;
		val ? write(1,"1",1) : write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
}

int	main()
{
	print_bits((unsigned char)' ');
	return (0);
}
