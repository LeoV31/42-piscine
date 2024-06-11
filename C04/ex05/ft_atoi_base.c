/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:58:14 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/29 13:46:53 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

int	get_value(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	ft_num(char *str, char *base)
{
	int	num;
	int	base_len;
	int	val;

	val = 0;
	base_len = 0;
	num = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (*str && (get_value(*str, base) != -1))
	{
		val = get_value(*str, base);
		num = num * base_len + val;
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;

	sign = 1;
	if (test_base(base) == 0)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	return (ft_num(str, base) * sign);
}
/*
#include <stdio.h>
int main() {
    char str[] = "   -372b";
    char base[] = "0123456789abcdef";
    printf("Converted number: %d\n", ft_atoi_base(str, base));
    return 0;
}
*/
