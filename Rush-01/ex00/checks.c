/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:06:18 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/05 14:31:47 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_up(int tab[4][4], int inputs[16], int pos);
int	check_down(int tab[4][4], int inputs[16], int pos);
int	check_left(int tab[4][4], int inputs[16], int pos);
int	check_right(int tab[4][4], int inputs[16], int pos);

int	check_inputs(int tab[4][4], int inputs[16], int pos)
{
	if (check_up(tab, inputs, pos) == 0
		|| check_down(tab, inputs, pos) == 0
		|| check_left(tab, inputs, pos) == 0
		|| check_right(tab, inputs, pos) == 0)
		return (0);
	return (1);
}

int	check_up(int tab[4][4], int inputs[16], int pos)
{
	int	max;
	int	row;
	int	count;
	int	col;

	col = pos % 4;
	if ((pos / 4) == 3)
	{
		row = 0;
		max = 0;
		count = 0;
		while (row < 4)
		{
			if (tab[row][col] > max)
			{
				max = tab[row][col];
				count++;
			}
			row++;
		}
		if (count != inputs[col])
			return (0);
	}
	return (1);
}

int	check_down(int tab[4][4], int inputs[16], int pos)
{
	int	max;
	int	row;
	int	count;
	int	col;

	col = pos % 4;
	if ((pos / 4) == 3)
	{
		row = 3;
		max = 0;
		count = 0;
		while (row >= 0)
		{
			if (tab[row][col] > max)
			{
				max = tab[row][col];
				count++;
			}
			row--;
		}
		if (count != inputs[4 + col])
			return (0);
	}
	return (1);
}

int	check_left(int tab[4][4], int inputs[16], int pos)
{
	int	max;
	int	row;
	int	count;
	int	col;

	row = pos / 4;
	if ((pos % 4) == 3)
	{
		col = 0;
		max = 0;
		count = 0;
		while (col < 4)
		{
			if (tab[row][col] > max)
			{
				max = tab[row][col];
				count++;
			}
			col++;
		}
		if (count != inputs[8 + row])
			return (0);
	}
	return (1);
}

int	check_right(int tab[4][4], int inputs[16], int pos)
{
	int	max;
	int	row;
	int	count;
	int	col;

	row = pos / 4;
	if ((pos % 4) == 3)
	{
		col = 3;
		max = 0;
		count = 0;
		while (col >= 0)
		{
			if (tab[row][col] > max)
			{
				max = tab[row][col];
				count++;
			}
			col--;
		}
		if (count != inputs[12 + row])
			return (0);
	}
	return (1);
}
