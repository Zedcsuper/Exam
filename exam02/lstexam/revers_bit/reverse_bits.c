#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char res = 0;
	int	i;

	i = 0;
	while (i < 8)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
		i++;
		
	}
	return (res);
}

void	pritn_byte(unsigned char c)
{
	int	i;
	char	x;

	i = 7;
	while (i >= 0)
	{
		x = (c >> i) & 1;
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
	char c = '1';
	pritn_byte((unsigned char)c);
	unsigned char x = reverse_bits((unsigned char)c);
	pritn_byte(x);
	return (0);
}

















