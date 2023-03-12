/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: pull_from_b.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/06 16:33:43                                            */
/*   Updated:  2023/03/12 17:02:55                                            */
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
	int	count[2];
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
			count[0] = 0;
			count[1] = 0;
			while (aux)
			{
				if (*stacks->stack_b.top < pivot)
					do_move(rb, stacks);
				else
				{
					do_move(pa, stacks);
					count[0]++;
					chunk_size--;
					if (*stacks->stack_a.top < pivot2)
					{
						do_move(ra, stacks);
						count[0]--;
						count[1]++;
					}
				}
				aux--;
			}
			print_stacks(*stacks);
			sort_chunk_in_a(stacks, count[0]);
			print_stacks(*stacks);
			aux = count[1];
			while (aux)
			{
				do_move(rra, stacks);
				aux--;
			}
			aux = chunk_size;
			while (aux)
			{
				do_move(rrb, stacks);
				aux--;
			}
			print_stacks(*stacks);
			sort_chunk_in_a(stacks, count[1]);
			print_stacks(*stacks);
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
		pull_chunk(stacks, chunk_sizes[chunk_count - 1][1]);
		chunk_count--;
	}
}
