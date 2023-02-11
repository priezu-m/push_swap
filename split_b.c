/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: split_b.c                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/08 14:35:15                                            */
/*   Updated:  2023/02/11 15:15:52                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	something_to_do_in_b(t_stack stack_b, int bit)
{
	while (stack_b.top >= stack_b.bottom)
	{
		if (*stack_b.top & bit)
			return (true);
		stack_b.top--;
	}
	return (false);
}

void	split_b(t_stack *stack_a, t_stack *stack_b, int bit)
{
	while (something_to_do_in_b(*stack_b, bit))
	{
		if (!(*stack_b->top & bit))
			rotate(stack_b);
		else
			push_from_to(stack_b, stack_a);
	}
	derotate(stack_b);
}
