/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:21:15 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 20:06:31 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_putcontent(unsigned char *buf, int line_size, int canon)
{
	int	i;

	i = -1;
	while (i++ < 16)
	{
		if (i < line_size)
			ft_get_hex((unsigned long long)*(buf + i), 1);
		else if (i != 16)
			ft_putstr("  ", 2);
		if ((i == 7) && (canon == 1))
			ft_putstr("  ", 2);
		else if (i < 15)
			ft_putstr(" ", 1);
	}
	if (canon == 1)
		ft_putcontent_right(buf, line_size);
}

void	ft_putcontent_right(unsigned char *buf, int line_size)
{
	int	i;

	i = -1;
	ft_putstr("  |", 3);
	while (i++ < line_size - 1)
	{
		if (*(buf + i) <= 31 || *(buf + i) >= 127)
			ft_putstr(".", 1);
		else
			ft_putstr((char *)(buf + i), 1);
	}
	ft_putstr("|", 1);
}
