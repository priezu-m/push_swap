/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   test_move.c                                        :+:      :+:    :+:   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 14:16:25                                            */
/*   Updated: 2023/02/18 12:18:05 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <string.h>

int	find_next_pb(t_move direction, t_stacks_and_move_list *testing)
{
	int	bigger;
	int	i;

	if (testing->stacks.stack_a.current_size == 0)
		return (-1);
	if (testing->stacks.stack_b.current_size < 2)
		return (0);
	bigger = *(testing->stacks.stack_b.top - 1);
	if (*testing->stacks.stack_a.top > bigger)
		return (0);
	if (direction == ra)
	{
		i = 1;
		while (i < testing->stacks.stack_a.current_size)
		{
			if (testing->stacks.stack_a.top[-i] > bigger)
				return (i);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < testing->stacks.stack_a.current_size - 1)
		{
			if (testing->stacks.stack_a.bottom[i] > bigger)
				return (i + 1);
			i++;
		}
	}
	return (-1);

}

void	do_move(t_move move, t_stacks_and_move_list *testing)
{
	if (move == none)
		return ;
	if (move == sa)
	{
		testing->move_list.current_size++;
		testing->move_list.end++;
		*testing->move_list.end = move;
		execute_move(move, &testing->stacks);
		do_move(pb, testing);
		return ;
	}
	if (move == pb)
	{
		testing->move_list.current_size++;
		testing->move_list.end++;
		*testing->move_list.end = move;
		execute_move(move, &testing->stacks);
		if (testing->stacks.stack_b.current_size == 1)
			return ;
		else if (*testing->stacks.stack_b.top < *(testing->stacks.stack_b.top - 1))
			do_move(sb, testing);
		return ;
	}
	testing->move_list.current_size++;
	testing->move_list.end++;
	*testing->move_list.end = move;
	execute_move(move, &testing->stacks);
}

void	undo_move(t_move move, t_stacks_and_move_list *testing)
{
	if (move == none)
		return ;
	while (*testing->move_list.end != move)
		undo_move(*testing->move_list.end, testing);
	testing->move_list.current_size--;
	testing->move_list.end--;
	revert_move(move, &testing->stacks);
}

void	check_best(t_stacks_and_move_list *testing, t_stacks_and_move_list *best)
{
	if (testing->stacks.stack_b.current_size > best->stacks.stack_b.current_size)
	{
		best->stacks.stack_b.current_size = testing->stacks.stack_b.current_size;
		memcpy(best->stacks.stack_b.bottom, testing->stacks.stack_b.bottom, (size_t)best->stacks.stack_b.current_size * sizeof(int));
		best->stacks.stack_b.top = best->stacks.stack_b.bottom + best->stacks.stack_b.current_size - 1;
		best->stacks.stack_a.current_size = testing->stacks.stack_a.current_size;
		memcpy(best->stacks.stack_a.bottom, testing->stacks.stack_a.bottom, (size_t)best->stacks.stack_a.current_size * sizeof(int));
		best->stacks.stack_a.top = best->stacks.stack_a.bottom + best->stacks.stack_a.current_size - 1;
		best->move_list.current_size = testing->move_list.current_size;
		memcpy(best->move_list.start, testing->move_list.start, (size_t)best->move_list.current_size * sizeof(t_move));
		best->move_list.end = best->move_list.start + best->move_list.current_size - 1;
	}
	else if (testing->stacks.stack_b.current_size == best->stacks.stack_b.current_size)
	{
		if (testing->move_list.current_size < best->move_list.current_size)
		{
			best->stacks.stack_b.current_size = testing->stacks.stack_b.current_size;
			memcpy(best->stacks.stack_b.bottom, testing->stacks.stack_b.bottom, (size_t)best->stacks.stack_b.current_size * sizeof(int));
			best->stacks.stack_b.top = best->stacks.stack_b.bottom + best->stacks.stack_b.current_size - 1;
			best->stacks.stack_a.current_size = testing->stacks.stack_a.current_size;
			memcpy(best->stacks.stack_a.bottom, testing->stacks.stack_a.bottom, (size_t)best->stacks.stack_a.current_size * sizeof(int));
			best->stacks.stack_a.top = best->stacks.stack_a.bottom + best->stacks.stack_a.current_size - 1;
			best->move_list.current_size = testing->move_list.current_size;
			memcpy(best->move_list.start, testing->move_list.start, (size_t)best->move_list.current_size * sizeof(t_move));
			best->move_list.end = best->move_list.start + best->move_list.current_size - 1;
		}
	}
}

void	travel_to(t_move direction, int distance, t_stacks_and_move_list *testing)
{
	while (distance)
	{
		do_move(direction, testing);
		distance--;
	}
}

void	come_back(t_move direction, int distance, t_stacks_and_move_list *testing)
{
	while (distance)
	{
		undo_move(direction, testing);
		distance--;
	}
}

void	test_move(t_move direction, t_move move, t_stacks_and_move_list *testing, t_stacks_and_move_list *best)
{
	int	distance;

	if (testing->move_list.current_size >= testing->move_list.max_size - 1)
		return ;
	do_move(move, testing);
	check_best(testing, best);
	distance = find_next_pb(direction, testing);
	if (distance >= 0 && testing->move_list.current_size + distance < testing->move_list.max_size)
	{
		travel_to(direction, distance, testing);
		test_move(direction, pb, testing, best);
//		test_move(direction, ra, testing, best);
		come_back(direction, distance, testing);
	}
	undo_move(move, testing);
}

void find_best(t_stacks_and_move_list *testing, t_stacks_and_move_list *best)
{
	int	size;

	size = 0;
	while (size < testing->stacks.stack_a.current_size)
	{
		test_move(ra, none, testing, best);
		test_move(rra, none, testing, best);
		do_move(ra, testing);
		size++;
	}
	testing->move_list.end = testing->move_list.start - 1;
	testing->move_list.current_size = 0;
	while (size - 1)
	{
		test_move(ra, none, testing, best);
		test_move(rra, none, testing, best);
		do_move(rra, testing);
		size--;
	}
	testing->move_list.end = testing->move_list.start - 1;
	testing->move_list.current_size = 0;
}
