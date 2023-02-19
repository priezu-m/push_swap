/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/13 12:31:15                                            */
/*   Updated: 2023/02/18 00:54:53 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> //remove before evaluation
# include <string.h> //remove before evaluation
# include <stdbool.h>
# include <stddef.h>

# pragma GCC diagnostic warning "-Weverything"
# pragma GCC diagnostic ignored "-Wc++98-compat"

typedef struct s_stack_b
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_b;

typedef struct s_stack_a
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_a;

typedef struct s_stacks
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
}t_stacks;

typedef enum e_move
{
	none,
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}t_move;

typedef struct s_move_list
{
	t_move	*start;
	t_move	*end;
	int		max_size;
	int		current_size;
}t_move_list;

typedef struct s_stacks_and_move_list
{
	t_stacks	stacks;
	t_move_list	move_list;
}t_stacks_and_move_list;

void	execute_pa(t_stacks *stacks);
void	execute_pb(t_stacks *stacks);
void	execute_sa(t_stacks *stacks);
void	execute_sb(t_stacks *stacks);
void	execute_ss(t_stacks *stacks);
void	execute_ra(t_stacks *stacks);
void	execute_rb(t_stacks *stacks);
void	execute_rr(t_stacks *stacks);
void	execute_rra(t_stacks *stacks);
void	execute_rrb(t_stacks *stacks);
void	execute_rrr(t_stacks *stacks);

void	execute_move(t_move move, t_stacks *stacks);
void	revert_move(t_move  move, t_stacks *stacks);

void	print_stacks(t_stacks stacks);

void	init_stacks_and_move_list(t_stacks_and_move_list *stacks_and_move_list, int argc, char **argv);
void	destroy_stacks_and_move_list(t_stacks_and_move_list *stacks_and_move_list);

void	find_best(t_stacks_and_move_list *testing, t_stacks_and_move_list *best);
void	test_move(t_move direction, t_move move, t_stacks_and_move_list *testing, t_stacks_and_move_list *best);
void	do_move(t_move move, t_stacks_and_move_list *testing);
void	undo_move(t_move move, t_stacks_and_move_list *testing);
int		find_next_pb(t_move direction, t_stacks_and_move_list *testing);
void	check_best(t_stacks_and_move_list *testing, t_stacks_and_move_list *best);
void	travel_to(t_move direction, int distance, t_stacks_and_move_list *testing);
void	come_back(t_move direction, int distance, t_stacks_and_move_list *testing);

#endif

