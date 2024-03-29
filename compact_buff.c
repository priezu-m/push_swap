/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compact_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:38:47 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 15:05:58 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compact_buff.h"
#include "move_relations.h"
#include "ft_libc.h"
#include "stacks.h"
#include <stdbool.h>
#include <stddef.h>

static int	compact_opposite(t_move *buff, int *i, int *j, int *k)
{
	buff[*j] = neutral_of(buff[*k]);
	ft_memmove(&buff[(*k)], &buff[(*k) + 1],
		(size_t)((*i) - (*k)) * sizeof(int));
	(*i)--;
	return (1);
}

static int	compact_half_inverse(t_move *buff, int *i, int *j, int *k)
{
	buff[*j] = half_inverse_of(buff[*j], buff[*k]);
	ft_memmove(&buff[(*k)], &buff[(*k) + 1],
		(size_t)((*i) - (*k)) * sizeof(int));
	(*i)--;
	return (1);
}

static int	compact_inverse(t_move *buff, int *i, int *j, int *k)
{
	ft_memmove(&buff[(*k)], &buff[(*k) + 1],
		(size_t)((*i) - (*k)) * sizeof(int));
	(*i)--;
	ft_memmove(&buff[*j], &buff[(*j) + 1],
		(size_t)((*i) - ((*j))) * sizeof(int));
	(*i)--;
	return (2);
}

static int	compact_buff_internal(t_move *buff, int *i, int *j, int *k)
{
	int	count;

	count = 0;
	if (inverse_to_each_other(buff[*j], buff[*k]))
		count += compact_inverse(buff, i, j, k);
	else if (opposite_to_each_other(buff[*j], buff[*k]))
		count += compact_opposite(buff, i, j, k);
	else if (half_inverse_to_each_other(buff[*j], buff[*k]))
		count += compact_half_inverse(buff, i, j, k);
	*k = *j + 1;
	if (*k > *i)
		return (count);
	while (1)
	{
		if (inverse_to_each_other(buff[*j], buff[*k]))
			count += compact_inverse(buff, i, j, k);
		else if (opposite_to_each_other(buff[*j], buff[*k]))
			count += compact_opposite(buff, i, j, k);
		else if (half_inverse_to_each_other(buff[*j], buff[*k]))
			count += compact_half_inverse(buff, i, j, k);
		else
			break ;
	}
	return (count);
}

int	compact_buff(t_move *buff, int i)
{
	int	j;
	int	k;
	int	count;

	if (i == 0)
		return (0);
	count = 0;
	k = i;
	j = k - 1;
	while (j >= 0 && (neutral_to_each_other(buff[j], buff[k])))
		j--;
	if (j < 0)
		return (0);
	count += compact_buff_internal(buff, &i, &j, &k);
	j--;
	k = j + 1;
	count += compact_buff_internal(buff, &i, &j, &k);
	if ((i > 0) && half_inverse_to_each_other(buff[i - 1], buff[i]))
	{
		buff[i - 1] = half_inverse_of(buff[i - 1], buff[i]);
		count++;
	}
	return (count);
}
