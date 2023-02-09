/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename: basic_moves.c                                                  */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:18:39 by anon              #+#    #+#             */
/*   Updated:  2023/02/08 16:56:09                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int  const	tmp = *stack->bottom;
	int  const	size = (int )(stack->top - stack->bottom) + 1;

	buffer(push_move, "rr", stack->id);
	ft_memmove(stack->bottom, stack->bottom + 1, sizeof(int) * (unsigned)(size - 1));
	*stack->top = tmp;
	if (stack->rotation)
		stack->rotation--;
	else
		stack->rotation = (int)(stack->top - stack->bottom);
}

void	rotate(t_stack *stack)
{
	int  const	tmp = *stack->top;
	int  const	size = (int )(stack->top - stack->bottom) + 1;

	buffer(push_move, "r", stack->id);
	ft_memmove(stack->bottom + 1, stack->bottom, sizeof(int) * (unsigned)(size - 1));
	*stack->bottom = tmp;
	stack->rotation++;
}

void	push_from_to(t_stack *stack_a, t_stack *stack_b)
{
	buffer(push_move, "p", stack_b->id);
	stack_b->top++;
	*stack_b->top = *stack_a->top;
	stack_a->top--;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top > stack->bottom)
	{
		tmp = *stack->top;
		*stack->top = *(stack->top - 1);
		*(stack->top - 1) = tmp;
	}
	buffer(push_move, "s", stack->id);
}

void	derotate(t_stack *stack)
{
	int  const	size = (int )(stack->top - stack->bottom) + 1;

	if (stack->rotation >  (size - stack->rotation))
	{
		while (size > stack->rotation)
			rotate(stack);
		stack->rotation = 0;
	}
	else if (size > stack->rotation)
	{
		while (stack->rotation)
			reverse_rotate(stack);
	}
}
