/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:12:07 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:12:28 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

typedef struct s_stack_a
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_a;

typedef struct s_stack_b
{
	int	*bottom;
	int	*top;
	int	current_size;
	int	max_size;
}t_stack_b;

typedef enum e_move
{
	none,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss,
	pa,
	pb
}t_move;

typedef struct s_stacks
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
}t_stacks;

void	init_stacks(t_stacks *stacks, int argc, char **argv);
void	destroy_stacks(t_stacks stacks);
void	do_move(t_move move, t_stacks *stacks);

#endif
