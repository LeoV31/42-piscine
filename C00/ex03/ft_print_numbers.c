/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:53:08 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/24 20:27:13 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	ch;
	int		nb;

	nb = 0;
	while (nb <= 9)
	{
		ch = nb + '0';
		write(1, &ch, 1);
		nb++;
	}
}
