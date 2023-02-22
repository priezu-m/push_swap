/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: basic_moves.h                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 13:17:34                                            */
/*   Updated:  2023/02/21 16:42:26                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef BASIC_MOVES
# define BASIC_MOVES

# include "stacks.h"

void	rotate_a(t_stack_a *stack_a);
void	rotate_b(t_stack_b *stack_b);
void	rotate_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	reverse_rotate_a(t_stack_a *stack_a);
void	reverse_rotate_b(t_stack_b *stack_b);
void	reverse_rotate_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	swap_a(t_stack_a *stack_a);
void	swap_b(t_stack_b *stack_b);
void	swap_both(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_to_a(t_stack_a *stack_a, t_stack_b *stack_b);
void	push_to_b(t_stack_a *stack_a, t_stack_b *stack_b);

#endif
