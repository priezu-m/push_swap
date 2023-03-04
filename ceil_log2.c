/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ceil_log2.c                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/03/04 17:49:42                                            */
/*   Updated:  2023/03/04 17:51:06                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

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
