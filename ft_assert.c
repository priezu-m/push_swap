/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ft_assert.c                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 17:53:32                                            */
/*   Updated:  2023/02/20 17:58:18                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#include "ft_assert.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_assert(bool expression)
{
	if (expression == false)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
}
