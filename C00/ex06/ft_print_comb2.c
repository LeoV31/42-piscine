/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:53:01 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/25 13:57:07 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ecrire(int a)
{
	char	d;
	char	u;

	if (a <= 9)
	{
		d = 48;
		u = a + 48;
	}
	else
	{
		d = ((a / 10) + 48);
		u = (a - ((d - 48) * 10) + 48);
	}
	write(1, &d, 1);
	write(1, &u, 1);
}

void	separation(int a)
{
	if (a != 98)
		write(1, ", ", 2);
}

void	boucle(int a, int b)
{
	while (b > a && a <= 98)
	{
		ecrire(a);
		write(1, " ", 1);
		ecrire(b);
		separation(a);
		if (b == 99)
		{
			a++;
			b = a + 1;
		}
		else
			b++;
	}
}

void	ft_print_comb2(void)
{
	boucle(0, 1);
}
