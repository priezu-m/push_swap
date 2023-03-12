/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_chunk_in_a.c                                              */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/09 16:38:05                                            */
/*   Updated:  2023/03/12 16:50:38                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "sort_chunk_in_a.h"
#include "ft_math.h"
#include "pull_from_b.h"
#include "final_chunck_sort.h"
#include <stdlib.h>

void sort_chunk_in_a(t_stacks *stacks, int chunk_size)
{
	int (* const	chunk_sizes)[2] = calloc(sizeof(int) * 2, (size_t)ceil_log2(chunk_size));
	int				aux;
	int				pivot_a;
	int				pivot_b;
	int				i;

	pivot_a = get_min(stacks->stack_a.top - (chunk_size - 1), chunk_size) + chunk_size;
	pivot_a = ceil_div(pivot_a, 2);
	pivot_b = get_min(stacks->stack_a.top - (chunk_size - 1), chunk_size) + pivot_a;
	pivot_b = pivot_b / 2;
	i = 0;
	while (chunk_size > 4)
	{
		aux = chunk_size;
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
		chunk_size /= 2;
		aux = pivot_a;
		pivot_a = pivot_a + chunk_size;
		pivot_a = ceil_div(pivot_a, 2);
		pivot_b = (aux + pivot_a) / 2;
		print_stacks(*stacks);
	}
	final_chunck_sort(stacks, chunk_sizes, i, chunk_size);
	print_stacks(*stacks);
	if (chunk_size != 4)
		i--;
	if (i > 0)
		pull_from_b(stacks, chunk_sizes, i);
	free(chunk_sizes);
}
