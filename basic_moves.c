/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: basic_moves.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 12:57:57                                            */
/*   Updated:  2023/02/16 21:20:40                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_pa(t_stacks *stacks)
{
	if (stacks->stack_b.current_size == 0)
		return ;
	stacks->stack_a.top++;
	stacks->stack_a.current_size++;
	*stacks->stack_a.top = *stacks->stack_b.top;
	stacks->stack_b.current_size--;
	stacks->stack_b.top--;
}

void	execute_pb(t_stacks *stacks)
{
	if (stacks->stack_a.current_size == 0)
		return ;
	stacks->stack_b.top++;
	stacks->stack_b.current_size++;
	*stacks->stack_b.top = *stacks->stack_a.top;
	stacks->stack_a.current_size--;
	stacks->stack_a.top--;
}

void	execute_sa(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_a.current_size < 2)
		return ;
	tmp = *stacks->stack_a.top;
	*stacks->stack_a.top = *(stacks->stack_a.top - 1);
	*(stacks->stack_a.top - 1) = tmp;
}

void	execute_sb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_b.current_size < 2)
		return ;
	tmp = *stacks->stack_b.top;
	*stacks->stack_b.top = *(stacks->stack_b.top - 1);
	*(stacks->stack_b.top - 1) = tmp;
}

void	execute_ss(t_stacks *stacks)
{
	execute_sa(stacks);
	execute_sb(stacks);
}

void	execute_ra(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_a.current_size < 2)
		return ;
	tmp = *stacks->stack_a.top;
	memmove(stacks->stack_a.bottom + 1, stacks->stack_a.bottom, (size_t)(stacks->stack_a.current_size - 1) * sizeof (int));
	*stacks->stack_a.bottom = tmp;
}

void	execute_rb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_b.current_size < 2)
		return ;
	tmp = *stacks->stack_b.top;
	memmove(stacks->stack_b.bottom + 1, stacks->stack_b.bottom, (size_t)(stacks->stack_b.current_size - 1) * sizeof (int));
	*stacks->stack_b.bottom = tmp;
}

void	execute_rr(t_stacks *stacks)
{
	execute_ra(stacks);
	execute_rb(stacks);
}

void	execute_rra(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_a.current_size < 2)
		return ;
	tmp = *stacks->stack_a.bottom;
	memmove(stacks->stack_a.bottom, stacks->stack_a.bottom + 1, (size_t)(stacks->stack_a.current_size - 1) * sizeof(int));
	*stacks->stack_a.top = tmp;
}

void	execute_rrb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->stack_b.current_size < 2)
		return ;
	tmp = *stacks->stack_b.bottom;
	memmove(stacks->stack_b.bottom, stacks->stack_b.bottom + 1, (size_t)(stacks->stack_b.current_size - 1) * sizeof(int));
	*stacks->stack_b.top = tmp;
}

void	execute_rrr(t_stacks *stacks)
{
	execute_rra(stacks);
	execute_rrb(stacks);
}
