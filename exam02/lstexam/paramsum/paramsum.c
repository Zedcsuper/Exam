#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}


int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] <= 32)
		i++;
	if (s[i] == '-')
		sign = -sign;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + s[i++] - '0';
	return (res * sign);
}

int	main(int ac, char **av)
{
	int	i;
	int	sum;

	sum = 0;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
			sum += ft_atoi(av[i++]);
		ft_putnbr(sum);
		ft_putchar('\n');
		ft_putnbr(ac - 1);
	}
	else
		write (1,"0", 1);
	write(1,"\n", 1);
	return (0);
}
