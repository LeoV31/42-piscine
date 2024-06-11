/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:21:41 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 19:45:19 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_check_dict(char **dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		j = 0;
		if (dict[i][j] != '\0')
		{
			if (ft_check_dict_helper(dict, i, j) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_dict_helper(char **dict, int i, int j)
{
	while (dict[i][j] == ' ' || dict[i][j] == '\t'
			|| dict[i][j] == '\n' || dict[i][j] == '\v'
			|| dict[i][j] == '\f' || dict[i][j] == '\r')
		j++;
	if (dict[i][j] == '+' || dict[i][j] == '-')
		j++;
	if (!(dict[i][j] >= '0' && dict[i][j] <= '9'))
		return (1);
	while (dict[i][j] >= '0' && dict[i][j] <= '9')
		j++;
	while (dict[i][j] == ' ')
		j++;
	if (dict[i][j] != ':')
		return (1);
	while (dict[i][j] == ' ')
		j++;
	while (dict[i][j] >= 32 && dict[i][j] <= 126)
		j++;
	if (dict[i][j] != '\0')
		return (1);
	return (0);
}
