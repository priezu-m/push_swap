/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: do_move.c                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 17:53:14                                            */
/*   Updated:  2023/02/20 17:53:16                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include "basic_moves.h"
#include "buffer.h"

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
}
