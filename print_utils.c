/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename: print_utils.c                                                  */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:14:06 by anon              #+#    #+#             */
/*   Updated:  2023/02/11 16:17:44                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_error_and_exit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	int i;

	while (stack_a.top >= stack_a.bottom || stack_b.top >= stack_b.bottom)
	{
		if (stack_a.top >= stack_a.bottom)
		{
			i = 15 - ceil_log2(*stack_a.top);
			while (i)
			{
				write(2, " ", 1);
				i--;
			}
			ft_putnbr(*stack_a.top);
			write(2, " ", 1);
			write(2, "|", 1);
		}
		else
		{
			write(2, "                                      ", 17);
			write(2, "|", 1);
		}
		if (stack_b.top >= stack_b.bottom)
		{
			i = 15 - ceil_log2(*stack_b.top);
			while (i)
			{
				write(2, " ", 1);
				i--;
			}
			ft_putnbr(*stack_b.top);
			write(2, " ", 1);
			write(2, "\n", 1);
		}
		else
		{
			write(2, "                                       ", 17);
			write(2, "\n", 1);
		}
		stack_a.top--;
		stack_b.top--;
	}
	write(2, "_____________________", 21);
	write(2, "________________\n\n", 18);
}
