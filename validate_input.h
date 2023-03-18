/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evaluation </var/mail/evaluation>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:12:47 by evaluation        #+#    #+#             */
/*   Updated: 2023/03/18 21:12:49 by evaluation       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INPUT_H
# define VALIDATE_INPUT_H

# include <stdbool.h>

void	validate_input(int argc, char **argv);
bool	is_sorted(int *arr, int size, bool cmp(int x, int y));

#endif
