/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename: stack_init.c                                                   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:12:42 by anon              #+#    #+#             */
/*   Updated:  2023/02/04 14:09:00                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	init_stack_a(t_stack stack_a, t_stack stack_b, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = stack_a.size;
	while (j)
	{
		stack_a.bottom[j - 1] = ft_atoi(argv[i]);
		i++;
		j--;
	}
	index_stack_a(stack_a, stack_b);
}

void	insert_in_position(int *stack_b, int val, int stack_size)
{
	ft_memmove(stack_b + 1, stack_b, sizeof(int) * (unsigned)stack_size);
	stack_b[0] = val;
}

void	insert_on_stack_b(int *stack_b, int val, int stack_size)
{
	int	min;
	int	max;

	min = 0;
	max = stack_size - 1;
	while ((min + 1) < max)
	{
		if (stack_b[(min + max) / 2] > val)
			max = (min + max) / 2;
		else if (stack_b[(min + max) / 2] < val)
			min = (min + max) / 2;
		else
			print_error_and_exit("duplicated integers given\n");
	}
	if (stack_b[max] < val)
		stack_b[max + 1] = val;
	else if (stack_b[min] > val)
		insert_in_position(&stack_b[min], val, stack_size - min);
	else if (stack_b[max] > val)
		insert_in_position(&stack_b[max], val, stack_size - max);
	else
		print_error_and_exit("duplicated integers given\n");
}

void	index_stack_a(t_stack stack_a, t_stack stack_b)
{
	int	i;
	int	j;

	stack_b.bottom[0] = stack_a.bottom[0];
	i = 1;
	while (i < stack_a.size)
	{
		insert_on_stack_b(stack_b.bottom, stack_a.bottom[i], i);
		i++;
	}
	i = 0;
	while (i < stack_a.size)
	{
		j = 0;
		while (stack_b.bottom[j] != stack_a.bottom[i])
			j++;
		stack_a.bottom[i] = (int)j;
		i++;
	}
}

int	ceil_log2(int  n)
{
	int	res;

	res = 0;
	while (n >= 2)
	{
		n /= 2;
		res++;
	}
	return (res);
}
