/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_stacks.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/22 17:54:57                                            */
/*   Updated:  2023/03/04 18:00:22                                            */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include "greater_lesser.h"
#include "validate_input.h"
#include "final_chunck_sort.h"
#include "ft_math.h"
#include <stdlib.h>

static void	set_up(t_stacks *stacks, int (*chunk_sizes)[2])
{
	int	aux;
	int	pivot_a;
	int	pivot_b;
	int	i;

	pivot_a = ceil_div(stacks->stack_a.current_size, 2);
	pivot_b = pivot_a / 2;
	i = 0;
	while (stacks->stack_a.current_size > 4)
	{
		aux = stacks->stack_a.current_size;
		while (aux)
		{
			if (*stacks->stack_a.top < pivot_a)
			{
				do_move(pb, stacks);
				if (*stacks->stack_b.top < pivot_b)
				{
					do_move(rb, stacks);
					chunk_sizes[i][1]++;
				}
				else
					chunk_sizes[i][0]++;
			}
			else
				do_move(ra, stacks);
			aux--;
		}
		i++;
		print_stacks(*stacks);
		aux = pivot_a;
		pivot_a = ceil_div(pivot_a + stacks->stack_a.max_size, 2);
		pivot_b = (aux + pivot_a) / 2;
	}
	final_chunck_sort(stacks, chunk_sizes, i);
	i--;
}

void	sort_stacks(t_stacks stacks)
{
	int	(* const chunk_sizes)[2] = calloc(sizeof(int) * 2, (size_t)ceil_log2(stacks.stack_a.max_size));

	print_stacks(stacks);
	set_up(&stacks, chunk_sizes);
	print_stacks(stacks);
	free(chunk_sizes);
}
