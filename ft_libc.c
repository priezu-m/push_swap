/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:21:00 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 16:28:22 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	char const	*s;
	char const	*lasts;
	char		*lastd ;

	d = dest;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}

static void	imemset(uint8_t *ptr, int c, size_t size)
{
	if (size > 1)
		imemset(ptr + 1, c, size - 1);
	if (size)
		*ptr = (uint8_t)c;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && ((SIZE_MAX / count) < size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
		imemset(ptr, 0, count * size);
	return (ptr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
