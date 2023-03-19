/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:33:56 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 15:06:40 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_moves.h"
#include "ft_libc.h"
#include <stddef.h>

void	rotate_a(t_stack_a *stack_a)
{
	int	tmp;

	if (stack_a->current_size < 2)
		return ;
	tmp = *stack_a->top;
	ft_memmove(stack_a->bottom + 1, stack_a->bottom,
		(size_t)(stack_a->current_size - 1) * sizeof (int));
	*stack_a->bottom = tmp;
}

void	rotate_b(t_stack_b *stack_b)
{
	int	tmp;

	if (stack_b->current_size < 2)
		return ;
	tmp = *stack_b->top;
	ft_memmove(stack_b->bottom + 1, stack_b->bottom,
		(size_t)(stack_b->current_size - 1) * sizeof (int));
	*stack_b->bottom = tmp;
}

void	rotate_both(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(t_stack_a *stack_a)
{
	int	tmp;

	if (stack_a->current_size < 2)
		return ;
	tmp = *stack_a->bottom;
	ft_memmove(stack_a->bottom, stack_a->bottom + 1,
		(size_t)(stack_a->current_size - 1) * sizeof (int));
	*stack_a->top = tmp;
}

void	reverse_rotate_b(t_stack_b *stack_b)
{
	int	tmp;

	if (stack_b->current_size < 2)
		return ;
	tmp = *stack_b->bottom;
	ft_memmove(stack_b->bottom, stack_b->bottom + 1,
		(size_t)(stack_b->current_size - 1) * sizeof (int));
	*stack_b->top = tmp;
}
