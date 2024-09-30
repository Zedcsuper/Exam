#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c , 1);
}

void	print_memory(const void *addr, size_t size)
{
	const char *base = "0123456789abcdef";
	size_t i = 0;
	unsigned char *str = (unsigned char *)addr;
	char line[17];
	int nb;
	int j;
	// until finshed with line
	while (i < size || i % 16 != 0)
	{
		if (i < size)
		{
			nb = str[i] / 16;
			ft_putchar(base[nb]);
			nb = str[i] % 16;
			ft_putchar(base[nb]);
			// Store printable characters
			line[i % 16] = (str[i] >= 32 && str[i] <= 126) ? str[i] : '.';
		}
		// Put space in last line 
		else
			write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0)
		{
			j = 0;
			while (j < 16)
			{
				// keep up with location
				//(i - 16 == beginning ofline) + j plase in line
				// last line
				if (i - 16 + j >= size)
					break;
				ft_putchar(line[j++]);
			}
			ft_putchar('\n');
			printf("%d\n", i);
		}
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	printf("sizetab =  %zu\n", sizeof(tab));
	return (0);
}
