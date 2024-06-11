/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:16:17 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 19:16:50 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_putstr(char *str, int size)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (size == 0)
	{
		while (str[len])
			len++;
		size = len;
	}
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
}
