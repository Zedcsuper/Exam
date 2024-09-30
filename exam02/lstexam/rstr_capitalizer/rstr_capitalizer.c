#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
//./rstr_capitalizer "Premier PETIT TesT" | cat -e
int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if ((av[i][j] >= 65 && av[i][j] <= 90) && (av[i][j + 1] != ' ' && av[i][j + 1] != '\t' && av[i][j + 1] != '\0'))
					av[i][j] += 32;
				else if ((av[i][j] >= 97 && av[i][j] <= 122) && (av[i][j + 1] == '\t' || av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
					av[i][j] -= 32;
				write(1, &av[i][j], 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
		
