#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned long hex)
{
	char	*base;

	base = "0123456789abcdef";
	if (hex >= 16)
		print_hex(hex / 16);
	ft_putchar(base[hex % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned long address = (unsigned long)addr;
	print_hex(address);
	ft_putchar(' ');
	unsigned char *ptr = (unsigned char *)addr;
	size_t	i = 0;
	while ( i < 4)
	{
		print_hex(ptr[i]);
		if (i < size - 1)
			ft_putchar(' ');
		i++;
	}
}

int	main()
{
	int	n;

	n = 42;
	printf("%p\n", &n);
	print_memory(&n, sizeof(&n));
	printf("\n");
	print_hex(-1);
	printf("\n");
	unsigned char *nptr =(unsigned char *) &n;
	int i = 0;
	while (i < 4)
	{
		print_hex(nptr[i]);
		i++;
	}
	printf("\n");
	i = 7;
	unsigned char *n2ptr = (unsigned char *)&nptr;
	while (i >= 0)
	{
		print_hex(n2ptr[i]);
		i--;
	}	



	return (0);
}
