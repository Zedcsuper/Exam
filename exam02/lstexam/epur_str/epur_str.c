#include <unistd.h>

int	main(int ac, char **str)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (str[1][i])
		{
			while ((str[1][i] == ' ' || str[1][i] == '\t') && str[1][i])
				i++;
			while ((str[1][i] != ' ' && str[1][i] != '\t') && str[1][i])
			{		
				write(1, &str[1][i], 1);
				i++;
			}
			while ((str[1][i] == ' ' || str[1][i] == '\t') && str[1][i])
				i++;
			if (str[1][i])
				write(1," ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
		
