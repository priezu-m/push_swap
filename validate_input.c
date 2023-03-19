/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:12:38 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 18:03:46 by priezu-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate_input.h"
#include "ft_assert.h"
#include "ft_libc.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

static bool	contains_nondigit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (true);
		str++;
	}
	return (false);
}

void	validate_input(int argc, char **argv)
{
	int	i;

	if (argc =< 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		ft_assert(contains_nondigit(argv[i]) == false);
		ft_assert(trunc_atoi(argv[i]) <= INT_MAX);
		ft_assert(trunc_atoi(argv[i]) >= INT_MIN);
		i++;
	}
}

bool	is_sorted(int *arr, int size, bool cmp(int x, int y))
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (cmp(arr[i], arr [i + 1]) == false)
			return (false);
		i++;
	}
	return (true);
}
