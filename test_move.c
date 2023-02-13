/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: test_move.c                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 14:16:25                                            */
/*   Updated:  2023/02/13 16:16:43                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <string.h>

void	do_move_and_add_to_list(t_move move, t_stacks_and_move_list *testing)
{
	if (move == none)
		return ;
	execute_move(move, &testing->stacks);
	testing->move_list.end++;
	testing->move_list.current_size++;
	*testing->move_list.end = move;
}

void	undo_move_and_remove_from_list(t_move move, t_stacks_and_move_list *testing)
{
	if (move == none)
		return ;
	revert_move(move, &testing->stacks);
	testing->move_list.end--;
	testing->move_list.current_size--;
}

bool	case_is_valid(t_stacks_and_move_list *testing)
{
	int	i;

	i = testing->stacks.stack_b.current_size;
	if (i < 2)
	{
		return (true);
	}
	while (i > 1)
	{
		if (testing->stacks.stack_b.bottom[i - 1] <  testing->stacks.stack_a.bottom[i - 2])
			return (false);
		i--;
	}
	return (true);
}

void	check_best(t_stacks_and_move_list *testing, t_stacks_and_move_list *best)
{
	if (testing->stacks.stack_b.current_size > best->stacks.stack_b.current_size)
	{
		best->stacks.stack_b.current_size = testing->stacks.stack_b.current_size;
		memcpy(best->stacks.stack_b.bottom, testing->stacks.stack_b.bottom, (size_t)testing->stacks.stack_b.current_size * sizeof(int));
		best->stacks.stack_b.top = best->stacks.stack_b.bottom + best->stacks.stack_b.current_size - 1;
		best->stacks.stack_a.current_size = testing->stacks.stack_a.current_size;
		memcpy(best->stacks.stack_a.bottom, testing->stacks.stack_a.bottom, (size_t)testing->stacks.stack_a.current_size * sizeof(int));
		best->stacks.stack_a.top = best->stacks.stack_a.bottom + best->stacks.stack_a.current_size - 1;
		best->move_list.current_size = testing->move_list.current_size;
		memcpy(best->move_list.start, testing->move_list.start, (size_t)testing->move_list.current_size * sizeof(int));
		best->move_list.end = best->move_list.start + best->move_list.current_size - 1;
	}
	else if (testing->stacks.stack_b.current_size == best->stacks.stack_b.current_size)
	{
		if (testing->move_list.current_size < best->move_list.current_size)
		{
			best->stacks.stack_b.current_size = testing->stacks.stack_b.current_size;
			memcpy(best->stacks.stack_b.bottom, testing->stacks.stack_b.bottom, (size_t)testing->stacks.stack_b.current_size * sizeof(int));
			best->stacks.stack_b.top = best->stacks.stack_b.bottom + best->stacks.stack_b.current_size - 1;
			best->stacks.stack_a.current_size = testing->stacks.stack_a.current_size;
			memcpy(best->stacks.stack_a.bottom, testing->stacks.stack_a.bottom, (size_t)testing->stacks.stack_a.current_size * sizeof(int));
			best->stacks.stack_a.top = best->stacks.stack_a.bottom + best->stacks.stack_a.current_size - 1;
			best->move_list.current_size = testing->move_list.current_size;
			memcpy(best->move_list.start, testing->move_list.start, (size_t)testing->move_list.current_size * sizeof(int));
			best->move_list.end = best->move_list.start + best->move_list.current_size - 1;
		}
	}
}

void test_move(t_move move, t_stacks_and_move_list *testing, t_stacks_and_move_list *best)
{
	if (testing->move_list.current_size == testing->move_list.max_size)
		return ;
	do_move_and_add_to_list(move, testing);
	if (!case_is_valid(testing))
	{
		undo_move_and_remove_from_list(move, testing);
		return ;
	}
	check_best(testing, best);
	if (move == pb)
	{
		test_move(rb, testing, best);
		test_move(sb, testing, best);
	}
	if (move != ra)
		test_move(rra, testing, best);
	if (move != rra)
		test_move(ra, testing, best);
	if (move != sa)
		test_move(sa, testing, best);
	test_move(pb, testing, best);
	undo_move_and_remove_from_list(move, testing);
}
