/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: print_stacks.c                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 13:41:05                                            */
/*   Updated:  2023/02/13 16:23:56                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stacks stacks)
{
	while (stacks.stack_a.current_size || stacks.stack_b.current_size)
	{
		if (stacks.stack_a.current_size > stacks.stack_b.current_size)
		{
			fprintf(stderr, "%8d\t|\n", *stacks.stack_a.top);
			stacks.stack_a.current_size--;
			stacks.stack_a.top--;
		}
		else if (stacks.stack_b.current_size > stacks.stack_a.current_size)
		{
			fprintf(stderr, "\t\t|%8d\n", *stacks.stack_b.top);
			stacks.stack_b.current_size--;
			stacks.stack_b.top--;
		}
		else
		{
			fprintf(stderr, "%8d\t|%8d\n", *stacks.stack_a.top, *stacks.stack_b.top);
			stacks.stack_b.current_size--;
			stacks.stack_a.current_size--;
			stacks.stack_b.top--;
			stacks.stack_a.top--;
		}
	}
	fprintf(stderr, "__________________________________\n");
}
