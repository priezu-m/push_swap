/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_inverse_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:04:26 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:04:27 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_relations.h"

static t_move	y_is_double(t_move x, t_move y)
{
	if (y == rr)
	{
		if (x == rra)
			return (rb);
		return (ra);
	}
	else if (y == rrr)
	{
		if (x == ra)
			return (rrb);
		return (rra);
	}
	else
	{
		if (x == sa)
			return (sb);
		return (sa);
	}
}

static t_move	x_is_double(t_move x, t_move y)
{
	if (x == rr)
	{
		if (y == rra)
			return (rb);
		return (ra);
	}
	else if (x == rrr)
	{
		if (y == ra)
			return (rrb);
		return (rra);
	}
	else
	{
		if (y == sa)
			return (sb);
		return (sa);
	}
}

t_move	half_inverse_of(t_move x, t_move y)
{
	if (x == rr || x == rrr || x == ss)
		return (x_is_double(x, y));
	return (y_is_double(x, y));
}
