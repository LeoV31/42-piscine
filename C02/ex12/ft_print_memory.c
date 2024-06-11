/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:44:06 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/08 20:36:58 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_get_hex(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
		ft_putchar('0', 1);
	if (nb >= 16)
	{
		ft_get_hex(nb / 16, 0);
		ft_get_hex(nb % 16, 0);
	}
	else
	{
		ft_putchar(base[nb], 1);
	}
}

void	ft_putaddr(unsigned long long addr)
{
	unsigned long long	addr_copy;
	int					i;

	addr_copy = addr;
	i = 1;
	while (i++ < 15)
	{
		if (addr_copy < 16)
			ft_putchar('0', 1);
		addr_copy /= 16;
	}
	ft_get_hex(addr, 0);
}

void	ft_putcontent(unsigned char *c, int size)
{
	int		i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ', 1);
		if (i < size)
		{
			ft_get_hex((unsigned long long)*(c + i), 1);
		}
		else if (i != 16)
		{
			ft_putchar(' ', 2);
		}
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			ft_putchar('.', 1);
		else
			ft_putchar(*(c + i), 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	line_size;

	i = 0;
	c = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			line_size = 16;
		else
			line_size = size % 16;
		ft_putaddr((unsigned long long)c + (i * 16));
		ft_putchar(':', 1);
		ft_putcontent(c + (i * 16), line_size);
		ft_putchar('\n', 1);
		i++;
	}
	return (addr);
}
/*
int	main(void)
{
	char	*addr = "Bonjour les aminches...c. est
   	fou.tout.ce qu on peut faire
   	avec...print_memory....lol.lol. .";
	ft_print_memory(addr, 500);
}
*/
