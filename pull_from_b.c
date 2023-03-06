/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: pull_from_b.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/06 16:33:43                                            */
/*   Updated:  2023/03/06 18:10:52                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "pull_from_b.h"
#include "atom_pull_from_b.h"
#include "sort_chunk_in_a.h"
#include "ft_math.h"


static void	pull_chunk(t_stacks *stacks, int chunk_size)
{
	int	aux;
	int	count;
	int	pivot;
	int	pivot2;

	while (chunk_size)
	{
		if (chunk_size <= 4)
		{
			atom_pull_from_b(stacks, chunk_size);
			chunk_size = 0;
		}
		else
		{
			pivot = get_min(stacks->stack_b.top - (chunk_size - 1), chunk_size) + (chunk_size / 2);
			pivot2 = pivot + (ceil_div(chunk_size, 2) / 2);
			aux = chunk_size;
			count = 0;
			while (aux)
			{
				if (*stacks->stack_b.top < pivot)
					do_move(rb, stacks);
				else
				{
					do_move(pa, stacks);
					chunk_size--;
					if (*stacks->stack_a.top < pivot2)
					{
						do_move(ra, stacks);
						count++;
					}
				}
				aux--;
			}
			sort_chunk_in_a(stacks, ceil_div(ceil_div(chunk_size, 2), 2));
			while (count)
			{
				do_move(rra, stacks);
				count--;
			}
			aux = chunk_size;
			while (aux)
			{
				do_move(rrb, stacks);
				aux--;
			}
			sort_chunk_in_a(stacks, ceil_div(chunk_size / 2, 2));
		}
	}
}

void	pull_from_b(t_stacks *stacks, int (*chunk_sizes)[2], int chunk_count)
{
	int	aux;

	while (chunk_count)
	{

		pull_chunk(stacks, chunk_sizes[chunk_count - 1][0]);
		aux = chunk_sizes[chunk_count - 1][1];
		if (aux != stacks->stack_b.current_size)
		{
			while (aux)
			{
				do_move(rrb, stacks);
				aux--;
			}
		}
		pull_chunk(stacks, chunk_sizes[chunk_count - 1][0]);
		chunk_count--;
	}
}
