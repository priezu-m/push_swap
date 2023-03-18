/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_relations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:05:14 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:05:20 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
