/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: init_stacks_and_move_list.c                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 13:52:56                                            */
/*   Updated:  2023/02/13 16:22:27                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

void	init_stacks_and_move_list(t_stacks_and_move_list *stacks_and_move_list, int	argc, char **argv)
{
	int	i;

	stacks_and_move_list->stacks.stack_a.bottom = malloc((size_t)(argc - 1) * sizeof(int));
	stacks_and_move_list->stacks.stack_a.top = stacks_and_move_list->stacks.stack_a.bottom + argc - 1 - 1;
	stacks_and_move_list->stacks.stack_a.current_size = argc - 1;
	stacks_and_move_list->stacks.stack_a.max_size = argc - 1;
	stacks_and_move_list->stacks.stack_b.bottom = malloc((size_t)(argc - 1) * sizeof(int));
	stacks_and_move_list->stacks.stack_b.top = stacks_and_move_list->stacks.stack_b.bottom - 1;
	stacks_and_move_list->stacks.stack_b.current_size = 0;
	stacks_and_move_list->stacks.stack_b.max_size = argc - 1;
	stacks_and_move_list->move_list.start = malloc((size_t)(argc - 1) * 3 * sizeof(t_move));
	stacks_and_move_list->move_list.end = stacks_and_move_list->move_list.start - 1;
	stacks_and_move_list->move_list.current_size = 0;
	stacks_and_move_list->move_list.max_size = (argc - 1) * 3;
	i = 0;
	while (i < (argc - 1))
	{
		stacks_and_move_list->stacks.stack_a.bottom[i] = atoi(argv[i + 1]);
		i++;
	}
}

void	destroy_stacks_and_move_list(t_stacks_and_move_list *stacks_and_move_list)
{
	free(stacks_and_move_list->move_list.start);
	free(stacks_and_move_list->stacks.stack_a.bottom);
	free(stacks_and_move_list->stacks.stack_b.bottom);
}
