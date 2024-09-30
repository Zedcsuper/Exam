#include <stdio.h>

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char digiits[17] = "0123456789abcdef";
	char digiits2[17] = "0123456789ABCDEF";
	
	while (base--)
		if (digiits[base] == c || digiits2[base] == c)
			return (1);
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

int	main()
{
	printf("%d\n", ft_atoi_base("10", 4));
	return (0);
}
