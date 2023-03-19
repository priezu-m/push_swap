/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename: sort_chunk_in_a.c                                              */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:07:04 by evaluation        #+#    #+#             */
/*   Updated:  2023/03/19 16:53:46                                            */
/*                                                                            */
/* ************************************************************************** */

#include "sort_chunk_in_a.h"
#include "ft_math.h"
#include "pull_from_b.h"
#include "final_chunck_sort.h"
#include "ft_assert.h"
#include "ft_libc.h"
#include <stdlib.h>

static void	set_pivots(int *pivot_a, int *pivot_b,
		t_stacks *stacks, int chunk_size)
{
	*pivot_a = get_min(stacks->stack_a.top - (chunk_size - 1), chunk_size);
	*pivot_a = ceil_div(*pivot_a + *pivot_a + chunk_size, 2);
	*pivot_b = get_min(stacks->stack_a.top - (chunk_size - 1), chunk_size);
	*pivot_b += *pivot_a;
	*pivot_b = *pivot_b / 2;
}

static void	derotate_a(int size, t_stacks *stacks)
{
	if (size == stacks->stack_a.current_size)
		return ;
	while (size)
	{
		do_move(rra, stacks);
		size--;
	}
}

static void	split_chunk(int chunk_size, t_stacks *stacks, int (*chunk_sizes)[2])
{
	int	pivot_a;
	int	pivot_b;

	set_pivots(&pivot_a, &pivot_b, stacks, chunk_size);
	while (chunk_size)
	{
		if (*stacks->stack_a.top < pivot_a)
		{
			do_move(pb, stacks);
			if (*stacks->stack_b.top < pivot_b)
			{
				do_move(rb, stacks);
				chunk_sizes[0][1]++;
			}
			else
				chunk_sizes[0][0]++;
		}
		else
			do_move(ra, stacks);
		chunk_size--;
	}
}

void	sort_chunk_in_a(t_stacks *stacks, int chunk_size)
{
	int	(*chunk_sizes)[2];
	int	i;

	chunk_sizes = ft_calloc(sizeof(int) * 2, (size_t)ceil_log2(chunk_size));
	ft_assert(chunk_sizes != NULL);
	i = 0;
	while (chunk_size > 4)
	{
		split_chunk(chunk_size, stacks, &chunk_sizes[i]);
		chunk_size -= chunk_sizes[i][0] + chunk_sizes[i][1];
		i++;
		derotate_a(chunk_size, stacks);
	}
	if (chunk_size == stacks->stack_a.current_size)
		final_chunck_sort_set_up(stacks, chunk_sizes, i);
	else
		final_chunck_sort(stacks, chunk_sizes, i, chunk_size);
	if (chunk_size != 4)
		i--;
	if (i > 0)
		pull_from_b(stacks, chunk_sizes, i);
	free(chunk_sizes);
}
