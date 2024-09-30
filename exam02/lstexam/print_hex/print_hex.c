#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res =(res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
		
void	print_hex(int n)
{
	if (n >= 16)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else
	{
		if  (n >= 0 && n <= 9)
			ft_putchar(n + '0');
		else if (n > 9 && n <= 15)
			ft_putchar(n + 87);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1,"\n", 1);
	return (0);
}	
