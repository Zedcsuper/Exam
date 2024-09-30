#include "rev_wstr.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		
		int x = word_count(argv[1] , ' ') - 1;
		printf("%d\n", x);
		char **retval = ft_split(argv[1], ' ');
		while (x >= 0)
		{
			printf("%s ", retval[x]);
			x--;
		}
	}
	printf("\n");
}
