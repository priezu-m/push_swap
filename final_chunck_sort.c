/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_chunck_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:04:00 by anon              #+#    #+#             */
/*   Updated: 2023/03/19 01:11:58 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "final_chunck_sort.h"
#include "ft_math.h"

static void	carry_back_3(t_stacks *stacks)
{
	if (stacks->stack_b.current_size > 1
		&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
	do_move(rrb, stacks);
	do_move(pa, stacks);
}

static void	carry_back_4(t_stacks *stacks)
{
	if (stacks->stack_b.current_size > 1
		&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
	do_move(rrb, stacks);
	do_move(rrb, stacks);
	if (stacks->stack_b.current_size > 1
		&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
}

static void	sort2(t_stacks *stacks)
{
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
}

static void	sort4(t_stacks *stacks)
{
	int const	pivot_a = get_min(stacks->stack_a.top - 3, 4) + 2;
	int			aux;

	aux = 4;
	while (aux)
	{
		if (*stacks->stack_a.top < pivot_a)
			do_move(pb, stacks);
		else
			do_move(ra, stacks);
		aux--;
	}
	do_move(rra, stacks);
	do_move(rra, stacks);
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
}

void	final_chunck_sort(t_stacks *stacks, int (*chunk_sizes)[2],
		int chunk_number, int chunk_size)
{
	if (chunk_size == 2)
	{
		sort2(stacks);
		if (chunk_number)
			carry_back_3(stacks);
	}
	else if (chunk_size == 3)
	{
		sort3(stacks);
		if (chunk_number)
		{
			if ((chunk_sizes[chunk_number - 1][0]
				+ chunk_sizes[chunk_number - 1][1]) == 4)
				carry_back_4(stacks);
			else
				carry_back_3(stacks);
		}
	}
	else if (chunk_size == 4)
		sort4(stacks);
}
