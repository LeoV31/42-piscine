/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:45:45 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 20:12:39 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

char	*ft_atoi_str(char *str)
{
	char	*max;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	str = ft_atoi_str_helper(str);
	if (*str == '\0')
		return (str);
	while (*str == '0' && ((*(str + 1) >= '0') && (*(str + 1) <= '9')))
		str++;
	max = str;
	while (*max >= '0' && *max <= '9')
		max++;
	if (*max)
		*str = '\0';
	*max = '\0';
	return (str);
}

char	*ft_atoi_str_helper(char *str)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			*str = '\0';
			return (str);
		}
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
	{
		*str = '\0';
		return (str);
	}
	return (str);
}
