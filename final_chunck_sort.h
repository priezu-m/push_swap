/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: final_chunck_sort.h                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/03 23:10:26                                            */
/*   Updated:  2023/03/09 17:41:36                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef FINAL_CHUNK_SORT_H
# define FINAL_CHUNK_SORT_H

# include "stacks.h"

void	final_chunck_sort_set_up(t_stacks *stacks, int (*chunk_sizes)[2], int chunk_number);
void	final_chunck_sort(t_stacks *stacks, int (*chunk_sizes)[2], int chunk_number, int chunk_size);
void	sort4_set_up(t_stacks *stacks);

#endif
