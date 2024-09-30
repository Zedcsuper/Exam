#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
	unsigned char res = octet << 4 | octet >> 4;
	return (res);
}

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char x;
	
	x = 0;
	i = 7;
	while (i >= 0)
	{
		x = (octet >> i) & 1;
		if (x)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
}

int	main()
{
	int	i;
	int	count;

	count = 0;
	i = 2;
	unsigned char *p = (unsigned char *)&i;
	while (count < 4)
	{
		print_bits(p[count]);
		count++;
	}
	write(1, "\n", 1);
	count = 0;
	while (count < 4)
	{
		unsigned char n = swap_bits(p[count]);
		print_bits(n);
		count++;
	}

	return (0);
}
