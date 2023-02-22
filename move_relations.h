/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: move_relations.h                                               */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/21 16:40:33                                            */
/*   Updated:  2023/02/22 16:48:48                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef  MOVE_RELATIONS_H
# define  MOVE_RELATIONS_H

# include "stacks.h"
# include <stdbool.h>

bool	neutral_to_each_other(t_move x, t_move y);
bool	half_inverse_to_each_other(t_move x, t_move y);
t_move	half_inverse_of(t_move x, t_move y);
bool	inverse_to_each_other(t_move x, t_move y);
bool	opposite_to_each_other(t_move x, t_move y);
t_move	neutral_of(t_move x);

#endif

