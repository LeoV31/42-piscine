/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:56:23 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/16 09:38:59 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_write_hexdump_helper6(int *repeated,
			unsigned long long pos, int canon)
{
	if (*repeated)
		*repeated = 0;
	ft_putpos_hex(pos, canon);
}

void	ft_write_hexdump_helper7(int repeated,
			unsigned long long pos, int canon)
{
	if (!repeated)
		ft_putpos_hex(pos, canon);
}

void	ft_write_hexdump_helper(int size, int canon, unsigned char *buf)
{
	int					i;
	int					line_size;
	unsigned long long	pos;
	int					repeated;
	unsigned char		*prev_line;

	prev_line = init_hexdump(&i, &repeated, &pos, &line_size);
	while (i * 16 < size)
	{
		ft_write_hexdump_helper4(i, size, &line_size);
		if (prev_line && ft_memcmp(buf + (i * 16),
				prev_line, line_size) == 0 && i > 0)
		{
			if (!repeated)
				ft_write_hexdump_helper3(&repeated);
		}
		else
		{
			ft_write_hexdump_helper6(&repeated, pos, canon);
			ft_write_hexdump_helper2(line_size, canon, buf, i);
		}
		pos += ft_write_hexdump_helper5(line_size, prev_line, buf, &i);
	}
	ft_write_hexdump_helper7(repeated, pos, canon);
	ft_putstr("\n", 1);
}
