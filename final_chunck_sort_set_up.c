/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_chunck_sort_set_up.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:39:40 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 01:17:27 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "final_chunck_sort.h"

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

static void	sort3_set_up(t_stacks *stacks)
{
	if (*stacks->stack_a.top == stacks->stack_a.max_size - 3)
	{
		do_move(pb, stacks);
		if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
			do_move(sa, stacks);
		do_move(pa, stacks);
	}
	else if (*(stacks->stack_a.top - 1) == stacks->stack_a.max_size - 3)
	{
		if (*(stacks->stack_a.top) == stacks->stack_a.max_size - 2)
			do_move(sa, stacks);
		else
			do_move(ra, stacks);
	}
	else if (*(stacks->stack_a.top - 2) == stacks->stack_a.max_size - 3)
	{
		if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
			do_move(sa, stacks);
		do_move(rra, stacks);
	}
}

static void	sort2(t_stacks *stacks)
{
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
}

void	final_chunck_sort_set_up(t_stacks *stacks,
		int (*chunk_sizes)[2], int chunk_number)
{
	if (stacks->stack_a.current_size == 2)
	{
		sort2(stacks);
		if (chunk_number)
			carry_back_3(stacks);
	}
	else if (stacks->stack_a.current_size == 3)
	{
		sort3_set_up(stacks);
		if (chunk_number)
		{
			if ((chunk_sizes[chunk_number - 1][0]
				+ chunk_sizes[chunk_number - 1][1]) == 4)
				carry_back_4(stacks);
			else
				carry_back_3(stacks);
		}
	}
	else if (stacks->stack_a.current_size == 4)
		sort4_set_up(stacks);
}
