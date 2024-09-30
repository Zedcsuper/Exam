#include <unistd.h>
//./last_word "         lorem,ipsum            " | cat -e

int	main(int ac, char **av)
{
		int	i;
		char *s = "   abc";
		i = 0;
		while (s[i])
			i++;
		i = i - 1;
		while (s[i] == ' ' && s[i] == '\t' && s[i])
			i--;
		while (s[i] != ' ' && s[i] != '\t' && s[i])
			i--;
		i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i])
			write(1, &s[i++], 1);
	write(1, "\n", 1);
	return (0);
}
		
