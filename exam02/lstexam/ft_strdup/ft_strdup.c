#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	if (!src)
		return (NULL);
	char	*dup;
	int		i;
	
	i = 0;
	dup = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main()
{
	char *s = "";
	char *ft = ft_strdup(s);
	char *dup = strdup(s);
	printf("ft [%s]\n", ft);
	printf("dp [%s]\n", dup);
	return (0);
}
















