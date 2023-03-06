/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: sort_chunk_in_a.c                                              */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/06 18:14:02                                            */
/*   Updated:  2023/03/06 18:24:05                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "sort_chunk_in_a.h"
#include "ft_math.h"
#include <stdlib.h>

void sort_chunk_in_a(t_stacks *stacks, int chunk_size)
{
	int (* const	chunk_sizes)[2] = calloc(sizeof(int) * 2, (size_t)ceil_log2(chunk_size));
	int				current_size;
	int				pivot_a;
	int				pivot_b;
	int				i;

	free(chunk_sizes);
}
