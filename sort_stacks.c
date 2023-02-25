/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/22 17:54:57                                            */
/*   Updated: 2023/02/25 19:49:48 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include "greater_lesser.h"
#include "validate_input.h"
#include "ft_math.h"

static void	split_b(t_stacks *stacks, int chunk_size);

static void	split_a(t_stacks *stacks, int chunk_size)
{
	int	a_pivot;
	int	b_pivot;

	a_pivot = ceil_div(stacks->stack_a.current_size, 2);
	a_pivot = a_pivot + !!(a_pivot % 2);
	b_pivot = a_pivot / 2;
	while (stacks->stack_a.current_size > 4)
	{

		a_pivot = ceil_div(stacks->stack_a.current_size, 2);
		a_pivot = a_pivot + !!(a_pivot % 2);
		b_pivot = (a_pivot + (stacks->stack_a.max_size - stacks->stack_a.current_size)) / 2;
	}

}

static void	split_b(t_stacks *stacks, int chunk_size)
{
}

void	sort_stacks(t_stacks stacks)
{
	print_stacks(stacks);
	split_a(&stacks, stacks.stack_a.current_size);
}
