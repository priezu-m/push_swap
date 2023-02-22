/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: buffer.h                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 13:17:14                                            */
/*   Updated:  2023/02/20 13:24:56                                            */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "stacks.h"

typedef enum e_buffer_action
{
	nothing = 0,
	push = 1,
	flush = 1 << 1,
}t_buffer_action;

void	buffer(t_buffer_action action, t_move move);

#endif
