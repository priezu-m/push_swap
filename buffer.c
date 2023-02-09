/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: buffer.c                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/02/07 11:33:09                                            */
/*   Updated:  2023/02/08 16:55:49                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buffer(t_buffer_action act, char mv[2], char id)
{
	static char		buff[10000][4];
	static size_t	i;
	size_t			j;
	size_t			k;

	if (act == push_move)
	{
		if (i == 10000)
			buffer(flush_buffer, 0, 0);
		buff[i][0] = mv[0];
		buff[i][1] = mv[1];
		buff[i][2] = id;
		buff[i][3] = '\0';
		i++;
	}
	else
	{
		j = 0;
		while (j < i)
		{
			k = 0;
			while (k < 4)
			{
				if (buff[j][k])
					write(1, &buff[j][k], 1);
				k++;
			}
			write(1, (char []){'\n'}, 1);
			j++;
		}
		i = 0;
	}
}
