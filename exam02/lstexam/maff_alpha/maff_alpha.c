#include <unistd.h>

int	main(void)
{
	int	i;
	char	c;
	i = 97;
	while (i <= 122)
	{
		c = i;
		if ( i % 2 != 0)
			write(1, &c, 1);
		else
		{
			c = i - 32;
			write(1, &c, 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
