/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ft_math.h                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/24 18:05:56                                            */
/*   Updated:  2023/02/24 18:10:01                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic warning "-Weverything"

#ifndef FT_MATH_H
# define FT_MATH_H

int	ft_min(int x, int y);
int	ft_max(int x, int y);
int	get_min(int *arr, int size);
int	get_max(int *arr, int size);
int	ceil_div(int x, int y);

#endif
