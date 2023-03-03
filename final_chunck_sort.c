/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: final_chunck_sort.c                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/03 23:12:02                                            */
/*   Updated:  2023/03/03 23:48:27                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "final_chunck_sort.h"

static void	carry_back_3(t_stacks *stacks)
{
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
	do_move(rrb, stacks);
	do_move(pa, stacks);
}

static void	carry_back_4(t_stacks *stacks)
{
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
	do_move(rrb, stacks);
	do_move(rrb, stacks);
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
}

static void	sort3_x(t_stacks *stacks)
{
	if (*stacks->stack_a.top == stacks->stack_a.max_size - 3)
		do_move(pb, stacks);
	else if (*(stacks->stack_a.top - 1) == stacks->stack_a.max_size - 3)
	{
		do_move(sa, stacks);
		if (stacks->stack_b.current_size > 0)
		{
			if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
				do_move(sb, stacks);
		}
		do_move(pb, stacks);
	}
	else if (*(stacks->stack_a.top - 2) == stacks->stack_a.max_size - 3)
	{
		do_move(rra, stacks);
		do_move(pb, stacks);
	}
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
	do_move(pa, stacks);
	if (stacks->stack_b.current_size % 2)
		carry_back_3(stacks);
	else
		carry_back_4(stacks);
}

static void	sort2_3(t_stacks *stacks)
{
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
	if (stacks->stack_b.current_size > 0)
	{
		carry_back_3(stacks);
	}
}

void	final_chunck_sort(t_stacks *stacks)
{
	if (stacks->stack_a.current_size == 2)
		sort2_3(stacks);
	else if (stacks->stack_a.current_size == 3)
		sort3_x(stacks);
	else if (stacks->stack_a.current_size == 4)
		sort4(stacks);
}
