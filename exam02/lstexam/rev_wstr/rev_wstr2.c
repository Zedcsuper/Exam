#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	count_word(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	return (count);
}

void	ft_strncpy(char *dst, char *src, int n)
{
	while (n--)
		*dst++ = *src++;
	*dst = '\0';
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}


char	*creat_word(char *s, int *index)
{
	int	i;
	char	*word;
	i = *index;
	while (s[*index] != ' ' && s[*index] != '\t' && s[*index])
		(*index)++;
	word = malloc(sizeof(char) * (*index - i + 1));
	if (!word)
		return (NULL);
	ft_strncpy(word, &s[i], *index - i);
	return (word);
}

char	**malloc_free(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		free(ar[i++]);
	free(ar);
	return (NULL);
}

char	**ft_split(char *s)
{
	int	i;
	int	index;
	int	wc;
	char	**ar;
	
	index = 0;
	i = 0;
	wc = count_word(s);
	ar = malloc(sizeof(char *) * (wc + 1));
	if (!ar)
		return (NULL);
	while (i < wc)
	{
		while (s[index] == ' ' || s[index] == '\t')
			index++;
		if (s[index])
		{
			ar[i] = creat_word(s, &index);
			if (!ar[i])
				return (malloc_free(ar));
		}
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
			
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = count_word(av[1]);
		char **ar = ft_split(av[1]);
		while (i--)
		{
			ft_putstr(ar[i]);
			if (i != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
