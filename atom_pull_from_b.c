/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom_pull_from_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:20:42 by anon              #+#    #+#             */
/*   Updated: 2023/03/17 11:27:06 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atom_pull_from_b.h"
#include "ft_math.h"

static void	atom_pull2(t_stacks *stacks)
{

}

static void	atom_pull3(t_stacks *stacks)
{

}

static void	atom_pull4(t_stacks *stacks)
{

}

void	atom_pull_from_b(t_stacks *stacks, int chunk_size)
{
	void (*const table[5])(t_stacks *) = {[2] = atom_pull2, [3] = atom_pull3, [4] = atom_pull4};
	int	aux;
	int	pivot;

	switch (chunk_size)
	{
		case 2:
		{
			do_move(pa, stacks);
			do_move(pa, stacks);
			if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
				do_move(sa, stacks);
			if (stacks->stack_b.current_size > 1 && (*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
				do_move(sb, stacks);
			break ;
		}
		case 3:
		{
			aux = get_min(stacks->stack_b.top - 2, 3);
			do_move(pa, stacks);
			if (*stacks->stack_a.top == aux)
			{
				do_move(ra, stacks);
				do_move(pa, stacks);
				do_move(pa, stacks);
				if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
					do_move(sa, stacks);
				do_move(rra, stacks);
				break ;
			}
			do_move(pa, stacks);
			if (*stacks->stack_a.top == aux)
			{
				do_move(ra, stacks);
				do_move(pa, stacks);
				if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
					do_move(sa, stacks);
				do_move(rra, stacks);
				break ;
			}
			if ((*stacks->stack_a.top > *(stacks->stack_a.top - 1)))
				do_move(sa, stacks);
			do_move(pa, stacks);
			break ;
		}
		case 4:
		{
			pivot = get_min(stacks->stack_b.top - 3, 4) + 2;
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
			break ;
		}
	}
}
