#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main()
{
	char *s1 = "aba";
	char *s2 = "";

	printf("ft = %d  cmp = %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	return (0);
}
