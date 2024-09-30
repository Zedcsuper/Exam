#include <stdio.h>
#include "rev_wstr.h"

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int	i;
		char	**retarr;
		int	len;
		char	*temp;

		retarr = ft_split(argv[1], ' ');
		len = word_count(argv[1], ' ');
		i = 1;
//		temp = retarr[0];
//		retarr[0] = retarr[len -1];
//		retarr[len -1] = temp;
		printf("******************\n");
		int x = 0;
		while (retarr[x])
			printf("%d %s\n", x, retarr[x++]);
		printf("******************\n");
		while (i < len)
			printf("%s ", retarr[i++]);
		printf("%s", retarr[0]);
	}
	printf("\n");
	return (0);
}
