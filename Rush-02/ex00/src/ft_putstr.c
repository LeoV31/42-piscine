/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:08:56 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/11 18:45:51 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/ft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
