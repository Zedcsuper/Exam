#include <stdlib.h>
#include <stdio.h>

int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c  && s[i])
				i++;
		}
	}
	return (count);
}

char	*ft_strncpy(char *dst, char *src, int len)
{
	while (len--)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}

char	*create_word(int *index, char *str, char c)
{
	int	i;
	char		*word;
	i = *index;
	while (str[*index] != c)
		(*index)++;
	word = malloc(sizeof(char) * (*index - i + 1));
	if (!word)
		return (NULL);
	ft_strncpy(word, &str[i], (*index) - i);
	return (word);
}



char	**ft_split(char *str, char c)
{
	int		index;
	char	**arr;
	int		wc;
	int		i;

	i = 0;
	wc = count_word(str, c);
	index = 0;
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		while (str[index] == c)
			index++;
		if (str[index])
			arr[i] = create_word(&index, str, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	main(void)
{
	char *s = "abc efg";
	int wc = count_word(s, ' ');
	int i = 0;
	char **ar = ft_split(s, ' ');
	while (i < wc)
		printf("%d :%s\n", i,ar[i++]);
	return (0);

}
