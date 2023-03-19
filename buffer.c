/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:37:54 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 14:28:01 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "compact_buff.h"
#include "stacks.h"
#include <unistd.h>

#define BUFF_SIZE 50000

static void	flush_before_exit(void)__attribute__((destructor));

static void	flush_before_exit(void)
{
	buffer(flush, none);
}

static void	print_move(t_move move)
{
	if (move == ra)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (move == rb)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (move == rr)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (move == rra)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (move == rrb)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (move == rrr)
		write(STDOUT_FILENO, "rrr\n", 4);
	else if (move == sa)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (move == sb)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (move == ss)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (move == pa)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (move == pb)
		write(STDOUT_FILENO, "pb\n", 3);
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
