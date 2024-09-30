#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	char	temp;
	
	j = 0;
	i = 0;
	while (str[i++]);
	//	i++;
	i -= 2;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return (str);
}

int	main()
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", s);
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}
	
