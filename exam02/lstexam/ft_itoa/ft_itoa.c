#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	long int	n;
	int		len;
	char	*number;
	long int	nbr2;
	int	len2;
	len = 0;
	
	n = (long)nbr;
	nbr2 = nbr;
	if (n <= 0)
		len++;
	while (nbr2)
	{
		len++;
		nbr2 /= 10;
	}
	len2 = len;
	number = malloc(sizeof(char) * (len + 1));
	if (nbr < 0)
	{
		number[0] = '-';
		n = -n;
	}
	if (n == 0)
		number[0] = '0';
	while (n)
	{
		number[--len] = n % 10 + '0';
		n /= 10;
	}
	number[len2] = '\0';
	return (number);
}

int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
}
