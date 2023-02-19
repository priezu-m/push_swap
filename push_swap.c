/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 12:51:49                                            */
/*   Updated: 2023/02/18 12:48:08 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_move_list(t_move_list best)
{
	int	i;

	i = 0;
	while (i < best.current_size)
	{
		if (best.start[i] == ra)
			printf("ra\n");
		else if (best.start[i] == rra)
			printf("rra\n");
		else if (best.start[i] == rb)
			printf("rb\n");
		else if (best.start[i] == rrb)
			printf("rrb\n");
		else if (best.start[i] == pb)
			printf("pb\n");
		else if (best.start[i] == pa)
			printf("pa\n");
		else if (best.start[i] == sb)
			printf("sb\n");
		else if (best.start[i] == sa)
			printf("sa\n");
		else
			printf("fuck\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks_and_move_list	testing;
	t_stacks_and_move_list	best;

	init_stacks_and_move_list(&testing, argc, argv);
	init_stacks_and_move_list(&best, argc, argv);
	print_stacks(best.stacks);
	while ( )
	{
		find_best(&testing, &best);
	}
	print_stacks(best.stacks);
	print_move_list(best.move_list);
	destroy_stacks_and_move_list(&testing);
	destroy_stacks_and_move_list(&best);
}
