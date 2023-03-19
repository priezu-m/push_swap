/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:36:06 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 14:26:00 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_moves.h"

void	reverse_rotate_both(t_stack_a *stack_a, t_stack_b *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}

void	swap_a(t_stack_a *stack_a)
{
	int	tmp;

	if (stack_a->current_size < 2)
		return ;
	tmp = *stack_a->top;
	*stack_a->top = *(stack_a->top - 1);
	*(stack_a->top - 1) = tmp;
}

void	swap_b(t_stack_b *stack_b)
{
	int	tmp;

	if (stack_b->current_size < 2)
		return ;
	tmp = *stack_b->top;
	*stack_b->top = *(stack_b->top - 1);
	*(stack_b->top - 1) = tmp;
}

void	swap_both(t_stack_a *stack_a, t_stack_b *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_to_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_b->current_size < 1)
		return ;
	stack_a->top++;
	stack_a->current_size++;
	*stack_a->top = *stack_b->top;
	stack_b->top--;
	stack_b->current_size--;
}
