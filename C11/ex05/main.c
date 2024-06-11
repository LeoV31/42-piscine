/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:34:17 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/10 14:52:17 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft.h"

int	main(int argc, char	**argv)
{
	int	a;
	int	b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
			write(2, "Stop : division by zero", 23);
		else if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
			write(2, "Stop : modulo by zero", 21);
		else if (argv[2][0] != '/' && argv[2][0] != '%'
			&& argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*')
			write(2, "0", 1);
		else
			ft_putnbr(ft_operations(a, b, argv[2][0]));
		write(1, "\n", 1);
	}
	return (1);
}

int	ft_operations(int a, int b, char sign)
{
	int	(*p[5])(int, int);
	int	result;

	result = 0;
	p[0] = sum;
	p[1] = sub;
	p[2] = mul;
	p[3] = div;
	p[4] = rest;
	if (sign == '+')
		result = p[0](a, b);
	if (sign == '-')
		result = p[1](a, b);
	if (sign == '*')
		result = p[2](a, b);
	if (sign == '/')
		result = p[3](a, b);
	if (sign == '%')
		result = p[4](a, b);
	return (result);
}
