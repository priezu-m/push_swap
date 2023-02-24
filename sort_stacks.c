/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_stacks.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/22 17:54:57                                            */
/*   Updated:  2023/02/24 18:48:56                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include "greater_lesser.h"
#include "validate_input.h"
#include "ft_math.h"

static void	split_b(t_stacks *stacks, int chunk_size);

static void	split_a(t_stacks *stacks, int chunk_size)
{
	int const	min = get_min(stacks->stack_a.top - chunk_size + 1, chunk_size);
	int const	max = get_max(stacks->stack_a.top - chunk_size + 1, chunk_size) + 1;
	int const	pivot = ceil_div(min + max, 2);
	int			size;

	if (chunk_size == 2)
	{
		if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
			do_move(sa, stacks);
	}
	if (is_sorted(stacks->stack_a.top - chunk_size + 1, chunk_size, greater))
	{
		while (chunk_size)
		{
			do_move(ra, stacks);
			chunk_size--;
		}
		return ;
	}
	size = chunk_size;
	while (size)
	{
		if (*stacks->stack_a.top < pivot)
			do_move(pb, stacks);
		else
			do_move(ra, stacks);
		size--;
	}
	print_stacks(*stacks);
	split_b(stacks, ceil_div(chunk_size, 2));
	split_a(stacks, chunk_size / 2);
}

static void	split_b(t_stacks *stacks, int chunk_size)
{
	int const	min = get_min(stacks->stack_b.top - chunk_size + 1, chunk_size);
	int const	max = get_max(stacks->stack_b.top - chunk_size + 1, chunk_size) + 1;
	int const	pivot = ceil_div(min + max, 2);
	int			size;

	if (chunk_size == 2)
	{
		if (*stacks->stack_b.top > *(stacks->stack_b.top - 1))
			do_move(sb, stacks);
	}
	if (is_sorted(stacks->stack_b.top - chunk_size + 1, chunk_size, greater))
	{
		while (chunk_size)
		{
			do_move(rb, stacks);
			chunk_size--;
		}
		return ;
	}
	size = chunk_size;
	while (size)
	{
		if (*stacks->stack_b.top < pivot)
			do_move(pa, stacks);
		else
			do_move(rb, stacks);
		size--;
	}
	print_stacks(*stacks);
	split_a(stacks, ceil_div(chunk_size, 2));
	split_b(stacks, chunk_size / 2);
}

void	sort_stacks(t_stacks stacks)
{
	print_stacks(stacks);
	split_a(&stacks, stacks.stack_a.current_size);
}
