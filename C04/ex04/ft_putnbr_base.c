/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:58:14 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/29 12:20:33 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (base[len] != '\0')
		len++;
	if (len < 2)
		return (0);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		base_len;

	base_len = 0;
	num = nbr;
	if (test_base(base) == 0)
		return ;
	while (base[base_len] != '\0')
		base_len++;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}
/*
#include <stdio.h>

int main() {
    printf("Affichage des nombres dans différentes bases:\n");

    // Affichage d'un nombre décimal en base 2 (binaire)
    printf("Nombre 42 en base 2 (binaire): ");
    ft_putnbr_base(42, "01");
    printf("\n");

    // Affichage d'un nombre décimal en base 16 (hexadécimal)
    printf("Nombre 255 en base 16 (hexadécimal): ");
    ft_putnbr_base(255, "0123456789ABCDEF");
    printf("\n");

    // Affichage d'un nombre décimal en base 8 (octal)
    printf("Nombre 100 en base 8 (octal): ");
    ft_putnbr_base(100, "poneyvif");
    printf("\n");

    // Affichage d'un nombre négatif en base 2 (binaire)
    printf("Nombre -30 en base 2 (binaire): ");
    ft_putnbr_base(-30, "01");
    printf("\n");

    // Affichage d'un nombre décimal en base 10 (décimal)
    printf("Nombre -123 en base 10 (décimal): ");
    ft_putnbr_base(-123, "0123456789");
    printf("\n");

    return 0;
}
*/
