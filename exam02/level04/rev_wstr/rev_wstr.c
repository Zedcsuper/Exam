#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	**ft_split(char *str)
{
	int	i;
	int	i2;
	int	i3;
	char		**tab;

	i = 0;
	i2 = 0;
	tab = (char**)malloc(sizeof(char) * 100);
	while (str[i])
	{
		if (str[i] > 32)
		{
			i3 = 0;
			tab[i2] = (char*)malloc(sizeof(char) * 100);
			while (str[i] > 32)
			{
				tab[i2][i3] = str[i];
				i++;
				i3++;
			}
			tab[i2][i3] = '\0';
			i2++;
		}	
		else
			i++;
	}
	tab[i2] = 0;
	return (tab);
}

int	main(int ac, char **av)
{
	int	i;
	char		**words;

	i = 0;
	if (ac == 2)
	{
		words = ft_split(av[1]);
		while (words[i])
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(words[i]);
			if (i > 0)
				write(1, "\n", 1);
			i--;
		}
	}
	printf("i = %d\n", i);
	write(1,"\n", 1);
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}






















