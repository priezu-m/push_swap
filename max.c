/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: max.c                                                          */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/08 14:16:24                                            */
/*   Updated:  2023/02/08 14:16:55                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
