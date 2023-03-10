/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: validate_input.h                                               */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/20 11:12:51                                            */
/*   Updated:  2023/02/24 16:52:23                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef VALIDATE_INPUT_H
# define VALIDATE_INPUT_H

# include <stdbool.h>

void	validate_input(int argc, char **argv);
bool	is_sorted(int *arr, int size, bool cmp(int x, int y));

#endif
