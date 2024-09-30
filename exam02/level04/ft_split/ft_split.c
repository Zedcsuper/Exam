#include <stdlib.h>
#include <stdio.h>
# define WD_NUM 1000
# define WD_LEN 1000

char	**ft_split(char *str)
{
	int	i;
	int	i2;
	int	i3;
	char		**tab;

	i = 0;
	i2 = 0;
	tab = (char**)malloc(sizeof(**tab) * WD_NUM);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			i3 = 0;
			tab[i2] = (char*)malloc(sizeof(char) * WD_LEN);
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
	if (ac == 2)
	{
		char **tab = ft_split(av[1]);
		int i = 0;
		while(tab[i])
			printf("%s\n", tab[i++]);
	}
	else
		printf("\n");
	return (0);
}
