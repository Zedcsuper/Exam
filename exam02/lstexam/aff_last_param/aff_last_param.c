#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	
	if (ac > 1)
	{
		int	i;

		i = 0;
		while (av[ac - 1][i])
		{
			write(1, &av[ac -1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
