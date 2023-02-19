/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 13:16:36                                            */
/*   Updated: 2023/02/18 11:06:11 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(t_move move, t_stacks *stacks)
{
	if (move == pa)
		execute_pa(stacks);
	else if (move == pb)
		execute_pb(stacks);
	else if (move == sa)
		execute_sa(stacks);
	else if (move == sb)
		execute_sb(stacks);
	else if (move == ss)
		execute_ss(stacks);
	else if (move == ra)
		execute_ra(stacks);
	else if (move == rb)
		execute_rb(stacks);
	else if (move == rr)
		execute_rr(stacks);
	else if (move == rra)
		execute_rra(stacks);
	else if (move == rrb)
		execute_rrb(stacks);
	else if (move == rrr)
		execute_rrr(stacks);
}

void	revert_move(t_move  move, t_stacks *stacks)
{
	if (move == pa)
		execute_pb(stacks);
	else if (move == pb)
		execute_pa(stacks);
	else if (move == sa)
		execute_sa(stacks);
	else if (move == sb)
		execute_sb(stacks);
	else if (move == ss)
		execute_ss(stacks);
	else if (move == ra)
		execute_rra(stacks);
	else if (move == rb)
		execute_rrb(stacks);
	else if (move == rr)
		execute_rrr(stacks);
	else if (move == rra)
		execute_ra(stacks);
	else if (move == rrb)
		execute_rb(stacks);
	else if (move == rrr)
		execute_rr(stacks);
}
