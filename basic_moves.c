/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: basic_moves.c                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 17:47:43                                            */
/*   Updated:  2023/02/20 17:51:48                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "basic_moves.h"
#include <string.h>
#include <stddef.h>

void	rotate_a(t_stack_a *stack_a)
{
	int	tmp;

	if (stack_a->current_size < 2)
		return ;
	tmp	= *stack_a->top;
	memmove(stack_a->bottom + 1, stack_a->bottom, (size_t)(stack_a->current_size - 1) * sizeof (int));
	*stack_a->bottom = tmp;
}

void	rotate_b(t_stack_b *stack_b)
{
	int	tmp;

	if (stack_b->current_size < 2)
		return ;
	tmp = *stack_b->top;
	memmove(stack_b->bottom + 1, stack_b->bottom, (size_t)(stack_b->current_size - 1) * sizeof (int));
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
	memmove(stack_a->bottom, stack_a->bottom + 1, (size_t)(stack_a->current_size - 1) * sizeof (int));
	*stack_a->top = tmp;
}

void	reverse_rotate_b(t_stack_b *stack_b)
{
	int	tmp;

	if (stack_b->current_size < 2)
		return ;
	tmp = *stack_b->bottom;
	memmove(stack_b->bottom, stack_b->bottom + 1, (size_t)(stack_b->current_size - 1) * sizeof (int));
	*stack_b->top = tmp;
}

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
