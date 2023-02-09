/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename: utils.c                                                        */
/*                                                    +:+ +:+         +:+     */
/*   By: anon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:11:30 by anon              #+#    #+#             */
/*   Updated:  2023/02/08 15:50:55                                            */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_memmove(void *dest, void const *src, size_t n)
{
	size_t	i;

	if (dest > src)
	{
		while (n)
		{
			((char *)dest)[n - 1] = ((char const *)src)[n - 1];
			n--;
		}
	}
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char const *)src)[i];
			i++;
		}
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned	res;
	int		i;
	bool		is_neg;

	is_neg = false;
	if (*str == '-')
	{
		is_neg = true;
		str++;
	}
	res = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] > '9') || str[i] < '0')
			print_error_and_exit("non interger given\n");
		if (((INT_MAX / 10) < res) ||
			(INT_MAX < (res * 10 + (unsigned)str[i] - '0' - is_neg)))
			print_error_and_exit("values bigger than integers given\n");
		res = (res * 10) + ((unsigned)(str[i] - '0'));
		i++;
	}
	if (is_neg)
		return ((int)-res);
	return ((int)res);
}

void	ft_putnbr(int nbr)
{
	char *const	base = "0123456789";

	if (nbr > 1)
		ft_putnbr(nbr / 2);
	write(2, &base[nbr % 2], 1);
}

bool	numbers_adjacent(int x, int y)
{
	if ((x + 1 == y) || (x - 1 == y))
		return (true);
	return (false);
}
