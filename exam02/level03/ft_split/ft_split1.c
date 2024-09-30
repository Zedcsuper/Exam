#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	word_count(char *str, char sep)
{
	int	i;
	int	wc;
	
	wc = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (wc);
}

char	**ft_split(char *str, char sep)
{
	char	**retarr;
	int	wc;
	int	j;
	int	i;

	j = 0;
	i = 0;
	wc = word_count(str, sep);
	retarr = (char **)malloc(sizeof(char *) * wc + 1);
	if (!retarr)
		return NULL;
	wc = 0;
	while (str[wc])
	{
		while (str[wc] && str[wc] == sep)
			wc++;
		j = wc;
		while (str[wc] && str[wc] != sep)
			wc++;
		if (wc > j)
		{
			retarr[i] = (char *)malloc(sizeof(char) * (wc - j) + 1);
			ft_strncpy(retarr[i], &str[j], (wc - j));
			i++;
		}
	}
	retarr[i] = 0;
	return (retarr);
}

int	main(void)
{
	char *s = "abc,efg,xy";
	int x = word_count(s, ',');
	printf("%s-> %d\n", s, x);
	char **split = ft_split(s, ',');
	x = 0;
	while (split[x])
		printf("%s.\n", split[x++]);
	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
	return (0);
}

