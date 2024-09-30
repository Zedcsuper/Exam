#include <unistd.h>

int	seen_before(char *s, char c , int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	if (ac == 3)
	{
//		./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//		df6ewg4$
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !seen_before(av[1], av[2][j], i ))
				{
					write(1, &av[1][i], 1);
					//j++;
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
		
