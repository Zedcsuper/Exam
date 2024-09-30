#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;
		char	c;

		i = 0;
		while (av[1][i])
		{
			c = av[1][i];
			if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'Z'))
				c += 13;
			else if ((c > 'm' && c <= 'z') || (c > 'M' && c <= 'Z'))
				c -= 13;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
