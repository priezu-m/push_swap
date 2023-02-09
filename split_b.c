/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: split_b.c                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/08 14:35:15                                            */
/*   Updated:  2023/02/09 17:03:15                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	segment_internaly_ordered_b(t_stack stack_b, int segment_size)
{
	while (segment_size > 1)
	{
		if (*(stack_b.top) < *(stack_b.top - 1))
			return (false);
		stack_b.top--;
		segment_size--;
	}
	return (true);
}

bool	something_to_do_in_b(t_stack stack_b, int bit)
{
	int	distance;
	int	segment_size;
	int	min_val_in_segment;

	stack_b.bottom += stack_b.rotation;
	distance = 0;
	while (stack_b.bottom <= stack_b.top)
	{
		if (*stack_b.bottom != distance)
			return (false);
		distance++;
		stack_b.bottom++;
	}
	while (stack_b.top >= stack_b.bottom)
	{
		segment_size = get_segment_size_in_b(stack_b);
		min_val_in_segment = get_min_val_in_segment(stack_b, segment_size);
		if (min_val_in_segment & bit)
			return (true);
		if (!segment_internaly_ordered_b(stack_b, segment_size))
			return (true);
		stack_b.top -= segment_size;
	}
	return (false);
}

int	get_segment_size_in_b(t_stack stack_b)
{
	int	top_value;
	int	segment_size;

	top_value = *stack_b.top;
	segment_size = 1;
	stack_b.top--;
	while (stack_b.top >= stack_b.bottom)
	{
		if (!numbers_adjacent(top_value, *stack_b.top))
			break ;
		top_value = ft_min(top_value, *stack_b.top);
		stack_b.top--;
		segment_size++;
	}
	return (segment_size);
}

int	get_min_val_in_segment(t_stack stack, int segment_size)
{
	int	min;

	min = *stack.top;
	stack.top--;
	segment_size--;
	while (segment_size)
	{
		min = ft_min(min, *stack.top);
		stack.top--;
		segment_size--;
	}
	return (min);
}

void	swap_sort_b(t_stack *stack_b)
{
	if (stack_b->top <= stack_b->bottom)
		return ;
	if (numbers_adjacent(*stack_b->top, *(stack_b->top - 1))
			&& (*stack_b->top < *(stack_b->top - 1)))
		swap(stack_b);
}

void	push_segment_form_b(t_stack *stack_a, t_stack *stack_b, int segment_size)
{
	push_from_to(stack_b, stack_a);
	swap_sort_a(stack_a);
	swap_sort_b(stack_b);
	segment_size--;
	while (segment_size)
	{
		push_from_to(stack_b, stack_a);
		swap_sort_a(stack_a);
		swap_sort_b(stack_b);
		segment_size--;
	}
}

void	rotate_segment_in_b(t_stack *stack_b, int segment_size)
{
	while (segment_size)
	{
		swap_sort_b(stack_b);
		rotate(stack_b);
		segment_size--;
	}
}

void	split_b(t_stack *stack_a, t_stack *stack_b, int bit, t_rotation_preservation rotation_preservation)
{
	int	segment_size;
	int	min_val_in_segment;

	while (something_to_do_in_b(*stack_b, bit))
	{
		segment_size = get_segment_size_in_b(*stack_b);
		min_val_in_segment = get_min_val_in_segment(*stack_b, segment_size);
		if ((segment_size == 1) && (stack_a->top >= stack_a->bottom) &&  numbers_adjacent(*stack_a->top, *stack_b->top))
			push_segment_form_b(stack_a, stack_b, segment_size);
		if (!(min_val_in_segment & bit))
			rotate_segment_in_b(stack_b, segment_size);
		else
			push_segment_form_b(stack_a, stack_b, segment_size);
		if (rotation_preservation == dont_preserve_rotation)
			stack_b->rotation = 0;
	}
	derotate(stack_b);
}
