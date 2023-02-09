/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_a.c                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/08 14:20:39                                            */
/*   Updated:  2023/02/08 19:33:42                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	something_to_do_in_a(t_stack stack_a, int bit)
{
	int	distance;
	int	max_val_in_segment;
	int	segment_size;

	stack_a.bottom += stack_a.rotation;
	distance = stack_a.size;
	while (stack_a.bottom <= stack_a.top)
	{
		if (*stack_a.bottom != distance)
			break ;
		distance--;
		stack_a.bottom++;
	}
	while (stack_a.top >= stack_a.bottom)
	{
		segment_size = get_segment_size_in_a(stack_a);
		max_val_in_segment = get_max_val_in_segment(stack_a, segment_size);
		if (!(max_val_in_segment & bit))
			return (true);
		stack_a.top -= segment_size;
	}
	return (false);
}

int	get_segment_size_in_a(t_stack stack_a)
{
	int	top_value;
	int	segment_size;

	top_value = *stack_a.top;
	segment_size = 1;
	stack_a.top--;
	while (stack_a.top >= stack_a.bottom)
	{
		if (!numbers_adjacent(top_value, *stack_a.top))
			break ;
		top_value = ft_max(top_value, *stack_a.top);
		stack_a.top--;
		segment_size++;
	}
	return (segment_size);
}

int	get_max_val_in_segment(t_stack stack, int segment_size)
{
	int	max;

	max = *stack.top;
	stack.top--;
	segment_size--;
	while (segment_size)
	{
		max = ft_max(max, *stack.top);
		stack.top--;
		segment_size--;
	}
	return (max);
}

void	swap_sort_a(t_stack *stack_a)
{
	if (stack_a->top <= stack_a->bottom)
		return ;
	if (numbers_adjacent(*stack_a->top, *(stack_a->top - 1))
			&& (*stack_a->top > *(stack_a->top - 1)))
		swap(stack_a);
}

void	push_segment_form_a(t_stack *stack_a, t_stack *stack_b, int segment_size)
{
	push_from_to(stack_a, stack_b);
	swap_sort_a(stack_a);
	swap_sort_b(stack_b);
	segment_size--;
	while (segment_size)
	{
		push_from_to(stack_a, stack_b);
		swap_sort_a(stack_a);
		swap_sort_b(stack_b);
		segment_size--;
	}
}

void	rotate_segment_in_a(t_stack *stack_a, int segment_size)
{
	while (segment_size)
	{
		swap_sort_a(stack_a);
		rotate(stack_a);
		segment_size--;
	}
}

void	split_a(t_stack *stack_a, t_stack *stack_b, int bit, t_rotation_preservation rotation_preservation)
{
	int	segment_size;
	int	max_val_in_segment;

	while (something_to_do_in_a(*stack_a, bit))
	{
		segment_size = get_segment_size_in_a(*stack_a);
		max_val_in_segment = get_max_val_in_segment(*stack_a, segment_size);
		if ((segment_size == 1) && (stack_b->top >= stack_b->bottom) && numbers_adjacent(*stack_a->top, *stack_b->top))
			push_segment_form_a(stack_a, stack_b, segment_size);
		if (max_val_in_segment & bit)
			rotate_segment_in_a(stack_a, segment_size);
		else
			push_segment_form_a(stack_a, stack_b, segment_size);
		if (rotation_preservation == dont_preserve_rotation)
			stack_a->rotation = 0;
	}
	derotate(stack_a);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;

	bit = 1;
	print_stacks(*stack_a, *stack_b);
	split_a(stack_a, stack_b, bit, dont_preserve_rotation);
	print_stacks(*stack_a, *stack_b);
	split_b(stack_a, stack_b, bit << 1, dont_preserve_rotation);
	print_stacks(*stack_a, *stack_b);
	bit <<= 1;
	while (bit <= stack_a->size)
	{
		split_a(stack_a, stack_b, bit, preserve_rotatioin);
		print_stacks(*stack_a, *stack_b);
		split_b(stack_a, stack_b, bit << 1, preserve_rotatioin);
		print_stacks(*stack_a, *stack_b);
		bit <<= 1;
	}
}
