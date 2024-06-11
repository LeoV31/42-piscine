/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:55:43 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 21:57:27 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_write_hexdump_helper2(int line_size, int canon,
			unsigned char *buf, int i)
{
	ft_putstr("  ", 1 + canon);
	ft_putcontent(buf + (i * 16), line_size, canon);
	ft_putstr("\n", 1);
}

void	ft_write_hexdump_helper3(int *repeated)
{
	ft_putstr("*\n", 2);
	*repeated = 1;
}

void	ft_write_hexdump_helper4(int i, int size, int *line_size)
{
	if (i < size / 16)
		*line_size = 16;
	else
		*line_size = size % 16;
}

int	ft_write_hexdump_helper5(int line_size, unsigned char *prev_line,
			unsigned char *buf, int *i)
{
	if (line_size == 16)
		ft_memcpy(prev_line, buf + (*i * 16), 16);
	(*i)++;
	return (line_size);
}
