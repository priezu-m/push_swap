/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: stacks.h                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 10:18:47                                            */
/*   Updated:  2023/02/22 17:56:29                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef T_STACKS_H
# define T_STACKS_H

typedef struct	s_stack_a
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_a;

typedef struct	s_stack_b
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_b;

typedef enum e_move
{
	none = 0,
	ra = 1,
	rb = 1 << 1,
	rr = 1 << 2,
	rra = 1 << 3,
	rrb = 1 << 4,
	rrr = 1 << 5,
	sa = 1 << 6,
	sb = 1 << 7,
	ss = 1 << 8,
	pa = 1 << 9,
	pb = 1 << 10
}t_move;

typedef struct s_stacks
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
}t_stacks;

void	init_stacks(t_stacks *stacks, int argc, char **argv);
void	print_stacks(t_stacks stacks);
void	destroy_stacks(t_stacks stacks);
void	sort_stacks(t_stacks stacks);
void	do_move(t_move move, t_stacks *stacks);

#endif
