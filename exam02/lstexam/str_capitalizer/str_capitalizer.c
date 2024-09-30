#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	isfirst;

	j = 0;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			isfirst = 1;
			while (av[i][j])	
			{
				while (av[i][j] <= 32)
				{
					isfirst = 1;
					j++;
				}
				if (av[i][j]) 
				{	
					if (av[i][j] >= 97 && av[i][j] <= 122 && isfirst)
					{
						av[i][j] -= 32;
						isfirst = 0;
					}
					j++;
				}
				while (av[i][j] > 32 && av[i][j])
				{	
					if (av[i][j] >= 65 && av[i][j] <= 90)
						av[i][j] += 32;
					j++;
				}	
			}
			write(1, av[i], j);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
