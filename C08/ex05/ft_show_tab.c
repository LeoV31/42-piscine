/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:46:43 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/05 11:20:08 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char a);
void	ft_putstr(char *str);
void	ft_putnbr(int size);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_putnbr(int size)
{
	long	n;

	n = size;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (size >= 10)
		ft_putnbr(size / 10);
	ft_putchar((size % 10) + '0');
}
/*
int	main(void)
{
	char *av[] = {"Hello", "World", "OpenAI", "Test"};
	int ac = sizeof(av) / sizeof(av[0]);
	t_stock_str *tab = ft_strs_to_tab(ac, av);

	ft_show_tab(tab);
	return (0);
}
*/
