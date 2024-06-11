/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:42:58 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/25 20:24:06 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ecrire(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == 55 && b == 56 && c == 57))
		write(1, ", ", 2);
}

void	boucle(char a, char b, char c)
{
	while (a < b < c && !(a == 55 && b == 56 && c == 57))
	{
		ecrire(a, b, c);
		if (b == 56 && c == 57)
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
		else if (c == 57 && b != 56)
		{
			b++;
			c = b + 1;
		}
		else if (! (a == 55 && b == 56 && c == 57))
		{
			c++;
		}
	}
	ecrire(a, b, c);
}

void	ft_print_comb(void)
{
	boucle(48, 49, 50);
}
