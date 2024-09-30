#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned long hex)
{
	if (hex >= 0 && hex <= 9)
		ft_putchar(hex + '0');
	else if (hex >= 10  && hex <= 15)
		ft_putchar(hex + 87);
	else
	{
		print_hex(hex / 16);
		print_hex(hex % 16);
	}
	
	
}
void	print_memory(const void *addr, size_t size)
{
	unsigned char *ptr = (unsigned char *)&addr;
	int	i;
	i = 8;
	while (i >= 0)
	{
		print_hex(ptr[i]);
		write(1, " ", 1);
		i--;
	}
		
	
}

int	main()
{
	int	n;

	n = 42;
	printf("%p\n", &n);
	print_memory(&n, sizeof(int *));
	printf("\n");
	return (0);
}
