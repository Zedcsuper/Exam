#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char	**malloc_free(char **v)
{
	int	i;

	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
	return (NULL);
}

int	count_word(char *s)
{
	int	count;
	int	i;

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
	{
		printf("%d nn", n);
		*dst++ = *src++;
	}
	printf("\n");
	*dst = '\0';
}

char	*create_word(char *src, int *index)
{
	int		i;
	char	*word;
	i = *index;
	while (src[*index] != ' ' && src[*index] != '\t' && src[*index])
		(*index)++;
	word = malloc(sizeof(char) * (*index - i + 1));
	if (!word)
		return (NULL);
	ft_strncpy(word, &src[i], (*index - i));
	return (word);
}

char	**ft_split(char *s)
{
	int		i;
	int		wc;
	int		index;
	char	**arr;

	index= 0;
	wc = count_word(s);
	arr = malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (i < wc)
	{
		while (s[index] == ' ' || s[index] == '\t')
			index++;
		if (s[index])
		{
			arr[i] = create_word(s, &index);
			if (!arr[i])
				return (malloc_free(arr));
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
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
	int		i;
	char	**ar;
//	char	**h;
//	h = ft_split("hi hi hi");
//	printf("%s %s %s\n", h[0], h[1], h[2]);
	i = 0;
	if (ac == 2)
	{
		ar = ft_split(av[1]);
		i = count_word(av[1]);
//		printf("%d\n", i);
		while (i--)
		{
		
			//printf("%d\n", i);
			ft_putstr(ar[i]);
			if (i != 0)
				write(1, " ", 1);

		}
		malloc_free(ar);
	}
	write(1, "\n", 1);
	return (0);
}
