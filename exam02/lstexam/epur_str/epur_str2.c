#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			if (av[1][i] && space)
				write(1, " ", 1);
			while (av[1][i] && av[1][i] != ' ' &&av[1][i] != '\t')
			{
				write(1, &av[1][i], 1);
				i++;
				space = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
