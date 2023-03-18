/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:37:33 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:37:43 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_MOVES_H
# define BASIC_MOVES_H

# include "stacks.h"

void	rotate_a(t_stack_a *stack_a);
void	rotate_b(t_stack_b *stack_b);
void	rotate_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	reverse_rotate_a(t_stack_a *stack_a);
void	reverse_rotate_b(t_stack_b *stack_b);
void	reverse_rotate_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	swap_a(t_stack_a *stack_a);
void	swap_b(t_stack_b *stack_b);
void	swap_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_to_a(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_to_b(t_stack_a *stack_a, t_stack_b *stack_b);

#endif
