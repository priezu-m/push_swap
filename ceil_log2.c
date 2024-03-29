/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_log2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:38:29 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:38:31 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdbool.h>

int	ceil_log2(int x)
{
	int		res;
	bool	remainder;

	res = 0;
	remainder = false;
	while (x > 1)
	{
		res++;
		if (!remainder)
			remainder = x % 2;
		x /= 2;
	}
	return (remainder + res);
}
