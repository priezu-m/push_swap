/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: push_swap.c                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/01/24 18:45:30                                            */
/*   Updated:  2023/02/08 19:14:18                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

int	main(int argc, char **argv)
{
	int const	param_count = argc - 1;
	t_stack				stack_a;
	t_stack				stack_b;

	if (argc < 3)
		print_error_and_exit("nothing given to sort\n");
	stack_a = (t_stack){.bottom = malloc(sizeof(int) * (unsigned)param_count), .size = param_count, .id = 'a', .rotation = 0};
	stack_b = (t_stack){.bottom = malloc(sizeof(int) * (unsigned)param_count), .size = param_count, .id = 'b', .rotation = 0};
	stack_a.top = stack_a.bottom + param_count - 1;
	stack_b.top = stack_b.bottom - 1;
	if (!stack_a.bottom || !stack_b.bottom)
		print_error_and_exit("memory error\n");
	init_stack_a(stack_a, stack_b, argv);
	sort_stack_a(&stack_a, &stack_b);
	buffer(flush_buffer, 0, 0);
	free(stack_a.bottom);
	free(stack_b.bottom);
}
