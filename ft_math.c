/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ft_math.c                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/24 18:07:35                                            */
/*   Updated:  2023/02/24 18:19:05                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "ft_math.h"
#include "limits.h"

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	get_min(int *arr, int size)
{
	int min;
	int	i;

	i = 0;
	min = INT_MAX;
	while (i < size)
	{
		min = ft_min(min, arr[i]);
		i++;
	}
	return (min);
}

int	get_max(int *arr, int size)
{
	int max;
	int	i;

	i = 0;
	max = INT_MIN;
	while (i < size)
	{
		max = ft_max(max, arr[i]);
		i++;
	}
	return (max);
}

int	ceil_div(int x, int y)
{
	return ((x / y) + !!(x % y));
}
