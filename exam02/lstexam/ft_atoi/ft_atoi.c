#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] < 33)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i])
		res = res * 10 + s[i++] - 48;
	return (res * sign);
}

int	main()
{

	printf("atoi  %d ft %d\n", atoi("-123"), ft_atoi("-123"));
	printf("atoi  %d ft %d\n", atoi("0"), ft_atoi("0"));
	printf("atoi  %d ft %d\n", atoi("19999"), ft_atoi("19999"));
	printf("atoi  %d ft %d\n", atoi("		-123"), ft_atoi("		-123"));
	return (0);
}
