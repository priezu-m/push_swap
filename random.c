/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: random.c                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/01/26 13:12:54                                            */
/*   Updated:  2023/01/26 13:24:22                                            */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int const	target = atoi(argv[1]);
	bool *const	table = calloc(target + 1, sizeof(bool));
	int			i;
	int			tmp;

	i = 0;
	srand(time(NULL));
	while (i < target)
	{
		tmp = (rand() % target) + 1;
		while (table[tmp])
			tmp = (rand() % target) + 1;
		table[tmp] = true;
		printf("%d ", tmp);
		i++;
	}
	printf("\n");
}
