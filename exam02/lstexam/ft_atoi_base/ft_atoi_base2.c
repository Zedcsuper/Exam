#include <stdio.h>

int	is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	is_valid(char c, int base)
{
	char *dig = "0123456789abcdef";
	char *dig2 = "0123456789ABCDEF";

	while (base--)
		if (dig[base] == c || dig2[base] == c)
			return (1);
	return (0);
}

int	ft_charval(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(char *s, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : 0;
	while (is_blank(*s))
		s++;
	while (is_valid(*s, str_base))
		result = result * str_base + ft_charval(*s++);
	return (result * sign);
}

int	main()
{
	printf("%d\n", ft_atoi_base("2a", 16));
	return (0);
}













