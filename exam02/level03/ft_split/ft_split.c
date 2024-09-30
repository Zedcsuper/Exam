#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//char *s = "ab de";
char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	wc;
	char		**out;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != '\t' && str[i] != ' '))
			i++;
	}
	out = (char **)malloc(sizeof(char **) * wc + 1);
	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		j = i;
		while (str[i] && (str[i] != '\t' && str[i] != ' '))
			i++;
		if (i > j)
		{
			out[wc] = (char *)malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy(out[wc++], &str[j], (i - j));
		}
	}
	out[wc] = NULL;
	return (out);
}

int	main(void)
{
	char *s = "ab de";
	printf("%s\n\n", s);
	char **test = ft_split(s);
	int i = 0;
	while (test[i])
		printf("%s\n", test[i++]);
	printf ("size of char* is %lu\n size of char ** is %lu\n",\
		sizeof(char *), sizeof(char **));
	return (0);
}













