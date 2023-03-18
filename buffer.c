/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:37:54 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 20:37:57 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "compact_buff.h"
#include "stacks.h"
#include <stdio.h>

#define BUFF_SIZE 50000

static void	flush_before_exit(void)__attribute__((destructor));

static void	flush_before_exit(void)
{
	buffer(flush, none);
}

static void	print_move(t_move move)
{
	if (move == ra)
		printf("ra\n");
	else if (move == rb)
		printf("rb\n");
	else if (move == rr)
		printf("rr\n");
	else if (move == rra)
		printf("rra\n");
	else if (move == rrb)
		printf("rrb\n");
	else if (move == rrr)
		printf("rrr\n");
	else if (move == sa)
		printf("sa\n");
	else if (move == sb)
		printf("sb\n");
	else if (move == ss)
		printf("ss\n");
	else if (move == pa)
		printf("pa\n");
	else if (move == pb)
		printf("pb\n");
}

void	buffer(t_buffer_action action, t_move move)
{
	static t_move	buff[BUFF_SIZE];
	static int		i;
	int				j;

	if (action == push)
	{
		if (i >= BUFF_SIZE)
			buffer(flush, none);
		buff[i] = move;
		i -= compact_buff(buff, i);
		i++;
	}
	else if (action == flush)
	{
		j = 0;
		while (j < i)
		{
			print_move(buff[j]);
			j++;
		}
		i = 0;
	}
}
