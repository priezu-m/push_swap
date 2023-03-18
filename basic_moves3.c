/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:36:57 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:37:21 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_moves.h"
#include <string.h>
#include <stddef.h>

void	push_to_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->current_size < 1)
		return ;
	stack_b->top++;
	stack_b->current_size++;
	*stack_b->top = *stack_a->top;
	stack_a->top--;
	stack_a->current_size--;
}
