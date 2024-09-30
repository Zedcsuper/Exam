#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
//	ft_putnbr(555);
	if (ac == 2)
	{
		int i = 1;
		int n = ft_atoi(av[1]);
		while ( i < 10)
		{
			ft_putnbr(i);
			write(1," x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(i * n);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}













