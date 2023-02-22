/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: half_inverse_of.c                                              */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/22 17:44:55                                            */
/*   Updated:  2023/02/22 17:49:14                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

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
