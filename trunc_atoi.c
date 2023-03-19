/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:43:50 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 16:28:53 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"
#include <limits.h>

static const char	*first_non_space(const char *str)
{
	if (' ' == *str || *str == '\f' || *str == '\n' || *str == '\r'
		||*str == '\t' || *str == '\v')
		return (first_non_space(str + 1));
	return (str);
}

static int	ndigit(const char *str)
{
	if (*str <= '9' && *str >= '0')
		return (1 + ndigit(str + 1));
	return (0);
}

static int long	elevate(int n)
{
	if (n)
		return (10 * elevate(n - 1));
	return (1);
}

static int long	atoi_inter(const char *str)
{
	if (ndigit(str) > 1)
		return ((*str - '0') * elevate(ndigit(str + 1)) + atoi_inter(str + 1));
	if (ndigit(str) == 1)
		return (*str - '0');
	return (0);
}

int long	trunc_atoi(char const *str)
{
	str = first_non_space(str);
	if (*str == '-')
	{
		if (ndigit(str + 1) > 10)
			return (LONG_MIN);
		return (-atoi_inter(str + 1));
	}
	if (*str == '+')
	{
		if (ndigit(str + 1) > 10)
			return (LONG_MAX);
		return (atoi_inter(str + 1));
	}
	if (ndigit(str + 1) > 10)
		return (LONG_MAX);
	return (atoi_inter(str));
}
