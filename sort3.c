/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 01:11:35 by anon              #+#    #+#             */
/*   Updated: 2023/03/19 01:24:37 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "final_chunck_sort.h"
#include "ft_math.h"

static void	sort3_helper_min_on_top(t_stacks *stacks)
{
	do_move(pb, stacks);
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
	{
		do_move(sa, stacks);
		if (stacks->stack_b.current_size > 1
			&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
			do_move(sb, stacks);
	}
	do_move(pa, stacks);
}

static void	sort3_helper_min_second(t_stacks *stacks, int min)
{
	if (*(stacks->stack_a.top) == min + 1)
	{
		do_move(sa, stacks);
		if (stacks->stack_b.current_size > 1
			&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
			do_move(sb, stacks);
	}
	else
	{
		do_move(sa, stacks);
		do_move(ra, stacks);
		do_move(sa, stacks);
		if (stacks->stack_b.current_size > 1
			&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
			do_move(sb, stacks);
		do_move(rra, stacks);
	}
}

static void	sort3_helper_min_third(t_stacks *stacks)
{
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
	{
		do_move(sa, stacks);
		if (stacks->stack_b.current_size > 1
			&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
			do_move(sb, stacks);
	}
	do_move(ra, stacks);
	do_move(ra, stacks);
	do_move(pb, stacks);
	do_move(rra, stacks);
	do_move(rra, stacks);
	do_move(pa, stacks);
}

void	sort3(t_stacks *stacks)
{
	int const	min = get_min(stacks->stack_a.top - 2, 3);

	if (*stacks->stack_a.top == min)
		sort3_helper_min_on_top(stacks);
	else if (*(stacks->stack_a.top - 1) == min)
		sort3_helper_min_second(stacks, min);
	else if (*(stacks->stack_a.top - 2) == min)
		sort3_helper_min_third(stacks);
}
