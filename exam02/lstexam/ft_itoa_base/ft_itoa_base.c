#include <stdlib.h>
#include <stdio.h>
#define abs(a) (a < 0) ? -a : a
char *g_base = "0123456789abcdef";
void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *)(b + len)) = (unsigned char) c;
	return (b);
}
char	*ft_itoa_base(int value, int base)
{
	int negative = (base == 10 && value < 0) ? 1 : 0;
	int size = (negative) ? 3 : 2;
	int temp = value;
	while (temp /= base)
		size++;
	char *res = malloc(sizeof(char) * size);
	ft_memset((void *)res, 'c', size);
	res[--size] = '\0';
//	res[--size] = g_base[abs(value % base)];
	while (value /= base)
		res[--size] = g_base[abs(value % base)];
	(negative) ? res[--size] = '-' : 0;
	return (res);
}
int	main()
{

	char *s = ft_itoa_base(999, 10);
	printf("%s\n", s);
	return (0);
}
