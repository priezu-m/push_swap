/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: move_relations.c                                               */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/21 16:52:13                                            */
/*   Updated:  2023/02/22 17:44:45                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "move_relations.h"

bool	half_inverse_to_each_other(t_move x, t_move y)
{
	if ((x == rr) && (y == rra || y == rrb))
		return (true);
	if ((y == rr) && (x == rra || x == rrb))
		return (true);
	if ((x == rrr) && (y == ra || y == rb))
		return (true);
	if ((y == rrr) && (x == ra || x == rb))
		return (true);
	if ((x == ss) && (y == sa || y == sb))
		return (true);
	if ((y == ss) && (x == sa || x == sb))
		return (true);
	return (false);
}

bool	neutral_to_each_other(t_move x, t_move y)
{
	if ((x == ra || x == rb) && (y == rr))
		return (true);
	else if ((y == ra || y == rb) && (x == rr))
		return (true);
	if ((x == sa || x == sb) && (y == ss))
		return (true);
	else if ((y == sa || y == sb) && (x == ss))
		return (true);
	if ((x == rra || x == rrb) && (y == rrr))
		return (true);
	else if ((y == rra || y == rrb) && (x == rrr))
		return (true);
	return (false);
}

bool	opposite_to_each_other(t_move x, t_move y)
{
	if ((x == ra) && (y == rb))
		return (true);
	else if ((y == ra) && (x == rb))
		return (true);
	if ((x == sa) && (y == sb))
		return (true);
	else if ((y == sa) && (x == sb))
		return (true);
	if ((x == rra) && (y == rrb))
		return (true);
	else if ((y == rra) && (x == rrb))
		return (true);
	return (false);
}

bool	inverse_to_each_other(t_move x, t_move y)
{
	if ((x == rb) && (y == rrb))
		return (true);
	if ((x == ra) && (y == rra))
		return (true);
	else if ((y == ra) && (x == rra))
		return (true);
	else if ((y == rb) && (x == rrb))
		return (true);
	else if ((x == sa) && (y == sa))
		return (true);
	else if ((x == sb) && (y == sb))
		return (true);
	else if ((x == pb) && (y == pa))
		return (true);
	else if ((x == pa) && (y == pb))
		return (true);
	else if ((x == rr) && (y == rrr))
		return (true);
	else if ((x == rrr) && (y == rr))
		return (true);
	else if ((x == ss) && (y == ss))
		return (true);
	return (false);
}

t_move	neutral_of(t_move x)
{
	if ((x == ra) || (x == rb))
		return (rr);
	if ((x == sa) || (x == sb))
		return (ss);
	return (rrr);
}
