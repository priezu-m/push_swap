/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: push_swap.h                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/01/24 18:45:48                                            */
/*   Updated:  2023/02/11 15:15:07                                            */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  ifdef __clang__
#  pragma GCC diagnostic warning "-Weverything"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef enum e_rotation_preservation
{
	dont_preserve_rotation,
	preserve_rotatioin
}t_rotation_preservation;

typedef enum e_buffer_action
{
	push_move,
	flush_buffer
}t_buffer_action;

typedef struct s_stack
{
	int		*bottom;
	int		*top;
	int		size;
	int		rotation;
	char	id;
}t_stack;

int		ft_atoi(char *str);
void	ft_putnbr( int nbr);
size_t	ft_strlen(char *str);
bool	numbers_adjacent(int x, int y);
int		ceil_log2(int n);
void	ft_memmove(void *dest, void const *src, size_t n);
void	init_stack_a(t_stack stack_a, t_stack stack_b, char **argv);
void	index_stack_a(t_stack stack_a, t_stack stack_b);
void	insert_on_stack_b(int *stack_b, int val, int stack_size);
void	insert_in_position(int *stack_b, int val, int stack_size);
void	print_stacks(t_stack stack_a, t_stack stack_b);
void	print_error_and_exit(char *str)__attribute__((noreturn));
void	push_from_to(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(t_stack *stack);
void	buffer(t_buffer_action act, char mv[2], char id);
void	derotate(t_stack *stack);
int		ft_max(int x, int y);
int		ft_min(int x, int y);
void	sort_stack_a(t_stack *stack_a, t_stack *stack_b);
void	split_a(t_stack *stack_a, t_stack *stack_b, int bit);
bool	something_to_do_in_a(t_stack stack_a, int bit);
int		get_segment_size_in_a(t_stack stack_a);
int		get_max_val_in_segment(t_stack stack, int segment_size);
void	split_b(t_stack *stack_a, t_stack *stack_b, int bit);
bool	something_to_do_in_b(t_stack stack_b, int bit);
int		get_segment_size_in_b(t_stack stack_b);
int		get_min_val_in_segment(t_stack stack, int segment_size);
void	push_segment_form_a(t_stack *stack_a, t_stack *stack_b, int segment_size);
void	push_segment_form_b(t_stack *stack_a, t_stack *stack_b, int segment_size);
void	swap_sort_a(t_stack *stack_a);
void	swap_sort_b(t_stack *stack_b);
void	rotate_segment_in_a(t_stack *stack_a, int segment_size);
void	rotate_segment_in_b(t_stack *stack_b, int segment_size);
bool	segment_internaly_ordered_b(t_stack stack_b, int segment_size);
bool	segment_internaly_ordered_a(t_stack stack_b, int segment_size);


#endif
