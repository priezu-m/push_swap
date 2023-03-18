/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:02:57 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:02:58 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
