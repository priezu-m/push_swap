/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:39:23 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:00:48 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "basic_moves.h"
#include "buffer.h"

static void	improve_order(t_stacks *stacks)
{
	if (stacks->stack_b.current_size > 1
		&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	if (stacks->stack_a.current_size > 1
		&& (*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
		do_move(sa, stacks);
}

void	do_move(t_move move, t_stacks *stacks)
{
	buffer(push, move);
	if (move == ra)
		rotate_a(&stacks->stack_a);
	else if (move == rb)
		rotate_b(&stacks->stack_b);
	else if (move == rr)
		rotate_both(&stacks->stack_a, &stacks->stack_b);
	else if (move == rra)
		reverse_rotate_a(&stacks->stack_a);
	else if (move == rrb)
		reverse_rotate_b(&stacks->stack_b);
	else if (move == rrr)
		reverse_rotate_both(&stacks->stack_a, &stacks->stack_b);
	else if (move == sa)
		swap_a(&stacks->stack_a);
	else if (move == sb)
		swap_b(&stacks->stack_b);
	else if (move == ss)
		swap_both(&stacks->stack_a, &stacks->stack_b);
	else if (move == pa)
		push_to_a(&stacks->stack_a, &stacks->stack_b);
	else if (move == pb)
		push_to_b(&stacks->stack_a, &stacks->stack_b);
	if (move == sa || move == sb)
		improve_order(stacks);
}
