/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:47:22 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 11:53:11 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_check_nbr(char *str)
{
	long long	nbr;

	nbr = ft_atoi(str);
	if (nbr < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
