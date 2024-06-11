/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:12:19 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/09 09:29:49 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str, int std, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		while (str[len])
			len++;
	}
	while (i < len)
	{
		ft_putchar(str[i], std);
		i++;
	}
}
