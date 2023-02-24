/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: validate_input.c                                               */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 17:55:44                                            */
/*   Updated:  2023/02/24 16:53:49                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "validate_input.h"
#include "ft_assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

static bool	contains_nondigit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (true);
		str++;
	}
	return (false);
}

void	validate_input(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_assert(argc > 2);
	i = 1;
	while (i < argc)
	{
		ft_assert(contains_nondigit(argv[i]) == false);
		ft_assert(strtol(argv[i], NULL, 10) <= INT_MAX);
		ft_assert(strtol(argv[i], NULL, 10) >= INT_MIN);
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
