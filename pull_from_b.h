/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: pull_from_b.h                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/06 16:31:15                                            */
/*   Updated:  2023/03/06 16:33:34                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef PULL_FROM_B_H
# define PULL_FROM_B_H

# include "stacks.h"

void	pull_from_b(t_stacks *stacks, int (*chunk_sizes)[2], int chunk_count);

#endif
