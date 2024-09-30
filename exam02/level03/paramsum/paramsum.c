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

int	main(int ac, char **av)
{
	(void)av;
	ac--;
	ft_putnbr(ac);
	ft_putchar('\n');
	return (0);
}
