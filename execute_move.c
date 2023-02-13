/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: execute_move.c                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 13:16:36                                            */
/*   Updated:  2023/02/13 13:40:32                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(t_move move, t_stacks *stacks)
{
	if (move == pa)
		execute_pa(stacks);
	if (move == pb)
		execute_pb(stacks);
	if (move == sa)
		execute_sa(stacks);
	if (move == sb)
		execute_sb(stacks);
	if (move == ss)
		execute_ss(stacks);
	if (move == ra)
		execute_ra(stacks);
	if (move == rb)
		execute_rb(stacks);
	if (move == rr)
		execute_rr(stacks);
	if (move == rra)
		execute_rra(stacks);
	if (move == rrb)
		execute_rrb(stacks);
	if (move == rrr)
		execute_rrr(stacks);
}

void	revert_move(t_move  move, t_stacks *stacks)
{
	if (move == pa)
		execute_pb(stacks);
	if (move == pb)
		execute_pa(stacks);
	if (move == sa)
		execute_sa(stacks);
	if (move == sb)
		execute_sb(stacks);
	if (move == ss)
		execute_ss(stacks);
	if (move == ra)
		execute_rra(stacks);
	if (move == rb)
		execute_rrb(stacks);
	if (move == rr)
		execute_rrr(stacks);
	if (move == rra)
		execute_ra(stacks);
	if (move == rrb)
		execute_rb(stacks);
	if (move == rrr)
		execute_rr(stacks);
}
