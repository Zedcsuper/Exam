#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;
		int	loop;

		i = 0;
		while (av[1][i])
		{
			loop = 1;
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				loop += av[1][i] - 'A';
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				loop += av[1][i] - 'a';
			while (loop)
			{
				write(1, &av[1][i], 1);
				loop--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}			
