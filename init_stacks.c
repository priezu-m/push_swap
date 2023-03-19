/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: priezu-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:55:40 by priezu-m          #+#    #+#             */
/*   Updated: 2023/03/19 17:55:41 by priezu-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_assert.h"
#include "stacks.h"
#include "ft_libc.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

static void	insert(int *arr, int val, int new_size)
{
	int	i;

	i = 0;
	while (i < new_size - 1)
	{
		ft_assert(arr[i] != val);
		if (arr[i] > val)
		{
			ft_memmove(&arr[i + 1], &arr[i],
				(size_t)(new_size - i - 1) * sizeof (int));
			arr[i] = val;
			return ;
		}
		i++;
	}
	arr[i] = val;
}

static void	index_array(int *arr, int size)
{
	int *const	aux_arr = malloc((size_t)size * sizeof (int));
	int			i;
	int			j;

	ft_assert(aux_arr != NULL);
	i = 0;
	while (i < size)
	{
		insert(aux_arr, arr[i], i + 1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (aux_arr[j] != arr[i])
			j++;
		arr[i] = j;
		i++;
	}
	free(aux_arr);
}

void	init_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	stacks->stack_b.max_size = argc - 1;
	stacks->stack_b.current_size = 0;
	stacks->stack_b.bottom = malloc((size_t)(argc - 1) * sizeof (int));
	ft_assert(stacks->stack_b.bottom != NULL);
	stacks->stack_b.top = stacks->stack_b.bottom - 1;
	stacks->stack_a.max_size = argc - 1;
	stacks->stack_a.current_size = argc - 1;
	stacks->stack_a.bottom = malloc((size_t)(argc - 1) * sizeof (int));
	ft_assert(stacks->stack_a.bottom != NULL);
	stacks->stack_a.top = stacks->stack_a.bottom + (argc - 1) - 1;
	i = 0;
	while (i < stacks->stack_a.max_size)
	{
		stacks->stack_a.bottom[i] = atoi(argv[argc - 1]);
		argc--;
		i++;
	}
	index_array(stacks->stack_a.bottom, stacks->stack_a.max_size);
}

void	destroy_stacks(t_stacks stacks)
{
	free(stacks.stack_a.bottom);
	free(stacks.stack_b.bottom);
}
