/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: push_swap.c                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 12:51:49                                            */
/*   Updated:  2023/02/13 14:16:10                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks_and_move_list	testing;
	t_stacks_and_move_list	best;

	init_stacks_and_move_list(&testing, argc, argv);
	init_stacks_and_move_list(&best, argc, argv);
	print_stacks(best.stacks);
	test_move(none, &testing, &best);
	print_stacks(best.stacks);
	destroy_stacks_and_move_list(&testing);
	destroy_stacks_and_move_list(&best);
}
