/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:20:19 by anon              #+#    #+#             */
/*   Updated: 2023/03/17 11:20:30 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"
#include "validate_input.h"
#include "greater_lesser.h"
#include "sort_chunk_in_a.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	validate_input(argc, argv);
	init_stacks(&stacks, argc, argv);
	if (is_sorted(stacks.stack_a.bottom, stacks.stack_a.current_size, greater))
	{
		destroy_stacks(stacks);
		return (0);
	}
	sort_chunk_in_a(&stacks, stacks.stack_a.current_size);
	destroy_stacks(stacks);
}
