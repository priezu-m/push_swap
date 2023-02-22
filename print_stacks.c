/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: print_stacks.c                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/22 17:57:21                                            */
/*   Updated:  2023/02/22 18:08:02                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include <stdio.h>

void	print_stacks(t_stacks stacks)
{
	while (stacks.stack_a.current_size || stacks.stack_b.current_size)
	{
		if (stacks.stack_a.current_size >= stacks.stack_b.current_size)
		{
			printf("%d", *stacks.stack_a.top);
			stacks.stack_a.current_size--;
			stacks.stack_a.top--;
		}
		printf("\t|");
		if (stacks.stack_b.current_size > stacks.stack_a.current_size)
		{
			printf("\t%d", *stacks.stack_b.top);
			stacks.stack_b.current_size--;
			stacks.stack_b.top--;
		}
		printf("\n");
	}
	printf("--------------------\n");
}
