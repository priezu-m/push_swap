/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort4_set_up.c                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/03 23:31:13                                            */
/*   Updated:  2023/03/09 17:18:46                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "final_chunck_sort.h"

void	sort4_set_up(t_stacks *stacks)
{
	int const	pivot_a = stacks->stack_a.max_size - 2;
	int			aux;

	aux = 4;
	while (aux)
	{
		if (*stacks->stack_a.top < pivot_a)
			do_move(pb, stacks);
		else
			do_move(ra, stacks);
		aux--;
	}
	if ((*stacks->stack_b.top < *(stacks->stack_b.top - 1)))
		do_move(sb, stacks);
	if (*stacks->stack_a.top > *(stacks->stack_a.top - 1))
		do_move(sa, stacks);
	do_move(pa, stacks);
	do_move(pa, stacks);
}
