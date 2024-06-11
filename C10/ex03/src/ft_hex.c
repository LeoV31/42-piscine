/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:20:25 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 19:21:59 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_putpos_hex(unsigned long long pos, int canon)
{
	unsigned long long	pos_copy;
	int					i;
	int					max;

	max = 6 + canon;
	pos_copy = pos;
	i = 0;
	while (i++ < max)
	{
		if (pos_copy < 16)
			ft_putstr("0", 1);
		pos_copy /= 16;
	}
	ft_get_hex(pos, 0);
}

void	ft_get_hex(unsigned long long pos, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (pos < 16 && prev == 1)
		ft_putstr("0", 1);
	if (pos >= 16)
	{
		ft_get_hex(pos / 16, 0);
		ft_get_hex(pos % 16, 0);
	}
	else
		ft_putstr(&base[pos], 1);
}
