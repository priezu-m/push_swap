/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_chunck_sort.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:02:16 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/19 01:11:06 by anon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINAL_CHUNCK_SORT_H
# define FINAL_CHUNCK_SORT_H

# include "stacks.h"

void	final_chunck_sort_set_up(t_stacks *stacks,
			int (*chunk_sizes)[2], int chunk_number);
void	final_chunck_sort(t_stacks *stacks,
			int (*chunk_sizes)[2], int chunk_number, int chunk_size);
void	sort4_set_up(t_stacks *stacks);
void	sort3(t_stacks *stacks);

#endif
