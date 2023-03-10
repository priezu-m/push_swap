/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.c                                                         */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 17:55:35                                            */
/*   Updated:  2023/02/24 17:11:08                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "stacks.h"
#include "validate_input.h"
#include "greater_lesser.h"

int main(int argc, char **argv)
{
	t_stacks	stacks;

	validate_input(argc, argv);
	init_stacks(&stacks, argc, argv);
	if (is_sorted(stacks.stack_a.bottom, stacks.stack_a.current_size, greater))
	{
		destroy_stacks(stacks);
		return (0);
	}
	sort_stacks(stacks);
	destroy_stacks(stacks);
}
