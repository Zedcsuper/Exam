#include <unistd.h>

int	not_seen(char *s, char c, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int	j;

		j = 0;
		i = 0;
		while (av[1][i])
		{
			if (not_seen(av[1],av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		while (av[2][j])
		{
			if (not_seen(av[2], av[2][j], j) && not_seen(av[1], av[2][j], i))
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
