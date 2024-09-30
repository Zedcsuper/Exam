#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**malloc_free(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		free(ar[i++]);
	free(ar);
	return (NULL);
}

int	word_count(char *s)
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
			while (s[i] != ' ' && s[i] != '\t' && s[i])
				i++;
		}
	}
	return (count);
}

void	ft_strncpy(char *d, char *s, int n)
{
	while (n--)
		*d++ = *s++;
	*d = '\0';
}

char	*create_word(char *d, char *s, int *index)
{
	int	i;

	i = *index;
	while (s[*index] != ' ' && s[*index] != '\t' && s[*index])
		(*index)++;
	d = malloc(sizeof(char) * (*index - i + 1));
	if (!d)
		return (NULL);
	ft_strncpy(d, &s[i], (*index - i));
	return (d);
}
	


char	**ft_split(char *s)
{
	int	i;
	int	index;
	int	wc;
	char	**ar;

	i = 0;
	wc = word_count(s);
	index = 0;
	ar = malloc(sizeof(char *) * (wc + 1));
	while (i < wc)
	{
		while (s[index] == ' ' || s[index] == '\t')
			index++;
		ar[i] = create_word(ar[i], s, &index);
		if (!ar[i])
			return (malloc_free(ar));
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	**ar;
		int	i;
		int	wc;

		ar = ft_split(av[1]);
		wc = word_count(av[1]);
		i = 1;
		while (i < wc)
		{
			ft_putstr(ar[i]);
			write(1, " ", 1);
			i++;
		}
		ft_putstr(ar[0]); 
		malloc_free(ar);
	}
	ft_putstr("\n");
	return (0);
}
