/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:38:11 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:38:16 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "stacks.h"

typedef enum e_buffer_action
{
	nothing = 0,
	push = 1,
	flush = 1 << 1
}t_buffer_action;

void	buffer(t_buffer_action action, t_move move);

#endif
