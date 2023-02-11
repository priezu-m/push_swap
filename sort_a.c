/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_a.c                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/08 14:20:39                                            */
/*   Updated:  2023/02/11 18:07:31                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	something_to_do_in_a(t_stack stack_a, int bit)
{
	while (stack_a.top >= stack_a.bottom)
	{
		if (!(*stack_a.top & bit))
			return (true);
		stack_a.top--;
	}
	return (false);
}

void	split_a(t_stack *stack_a, t_stack *stack_b, int bit)
{
	while (something_to_do_in_a(*stack_a, bit))
	{
		if (*stack_a->top & bit)
			rotate(stack_a);
		else
			push_from_to(stack_a, stack_b);
	}
	derotate(stack_a);
}

static void	sort_a_internal(t_stack *stack_a)
{
	int	size;

	size = (int)(stack_a->top - stack_a->bottom) + 1;
	while (size > 1)
	{
		if (*stack_a->top > *(stack_a->top - 1))
			swap(stack_a);
		rotate(stack_a);
		rotate(stack_a);
		size -= 2;
	}
	if (size)
		rotate(stack_a);
}

static void	merge(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = (int)(stack_b->top - stack_b->bottom) + 1;
	while (size > 1)
	{
		if (*stack_b->top < *(stack_b->top - 1))
			swap(stack_b);
		push_from_to(stack_b, stack_a);
		push_from_to(stack_b, stack_a);
		size -= 2;
	}
	if (size)
		push_from_to(stack_b, stack_a);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;

	bit = 1;
	print_stacks(*stack_a, *stack_b);
	while (bit <= ceil_log2(stack_a->size))
	{
		split_a(stack_a, stack_b, 1 << bit);
		print_stacks(*stack_a, *stack_b);
		split_b(stack_a, stack_b, 1 << bit);
		print_stacks(*stack_a, *stack_b);
		bit++;
	}
	sort_a_internal(stack_a);
	print_stacks(*stack_a, *stack_b);
	merge(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}
