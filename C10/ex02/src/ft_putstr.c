/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:12:19 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 10:12:21 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str, int len)
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
		write(1, &str[i], 1);
		i++;
	}
}
