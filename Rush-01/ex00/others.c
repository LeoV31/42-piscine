/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:36:40 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/05 14:57:43 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	check_row_col(int tab[4][4], int row, int col, int nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < col)
	{
		if (tab[row][j] == nbr)
			return (0);
		j++;
	}
	while (i < row)
	{
		if (tab[i][col] == nbr)
			return (0);
		i++;
	}
	return (1);
}

void	write_solution(int tab[4][4])
{
	int		i;
	int		j;
	char	a;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a = tab[i][j] + '0';
			write(1, &a, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	*to_numbers_helper(char *str, int *nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (i % 2) == 1)
			i++;
		else if ((str[i] >= 49 && str[i] <= 52) && (i % 2) == 0)
		{
			nbr[j] = str[i] - '0';
			i++;
			j++;
		}
		else
		{
			*nbr = -1;
			break ;
		}
	}
	return (nbr);
}

int	*to_numbers(char *str)
{
	int	*nbr;

	nbr = malloc(sizeof(int) * 17);
	if (nbr == NULL)
		return (NULL);
	nbr[16] = '\n';
	return (to_numbers_helper(str, nbr));
}
