/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom_pull_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:01:38 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:33:20 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atom_pull_from_b.h"
#include "ft_math.h"

static void	atom_pull2(t_stacks *stacks)
{
	do_move(pa, stacks);
	do_move(pa, stacks);
	if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
		do_move(sa, stacks);
	if (stacks->stack_b.current_size > 1
		&& (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
}

static void	atom_pull3_helper_smallest_on_top(t_stacks *stacks)
{
	do_move(ra, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
	if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
		do_move(sa, stacks);
	do_move(rra, stacks);
}

static void	atom_pull3(t_stacks *stacks)
{
	int const	aux = get_min(stacks->stack_b.top - 2, 3);

	do_move(pa, stacks);
	if (*stacks->stack_a.top == aux)
	{
		atom_pull3_helper_smallest_on_top(stacks);
		return ;
	}
	do_move(pa, stacks);
	if (*stacks->stack_a.top == aux)
	{
		do_move(ra, stacks);
		do_move(pa, stacks);
		if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
			do_move(sa, stacks);
		do_move(rra, stacks);
		return ;
	}
	if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
		do_move(sa, stacks);
	do_move(pa, stacks);
}

static void	atom_pull4(t_stacks *stacks)
{
	int const	pivot = get_min(stacks->stack_b.top - 3, 4) + 2;
	int			aux;

	aux = 4;
	while (aux)
	{
		if (*stacks->stack_b.top < pivot)
			do_move(rb, stacks);
		else
			do_move(pa, stacks);
		aux--;
	}
	do_move(rrb, stacks);
	do_move(rrb, stacks);
	if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
		do_move(sa, stacks);
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
}

void	atom_pull_from_b(t_stacks *stacks, int chunk_size)
{
	static void	(*table[5])(t_stacks *)
		= {[2] = atom_pull2, [3] = atom_pull3, [4] = atom_pull4};

	table[chunk_size](stacks);
}
