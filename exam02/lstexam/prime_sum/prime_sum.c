#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	int long ln = (long)n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln = ln * -1;
	}
	if (ln > 9)
	{
		ft_putnbr(ln / 10);
		ft_putnbr(ln % 10);
	}
	else
		ft_putchar(ln + '0');
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n < 2)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	prime_sum(int n)
{
	int	i;
	int	sum;

	sum = 0;
	i = 2;
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_atoi(av[1]) > 0)
		ft_putnbr(prime_sum(ft_atoi(av[1])));
	else
		write(1, "0", 1);
	ft_putchar('\n');
	return (0);
}














		
