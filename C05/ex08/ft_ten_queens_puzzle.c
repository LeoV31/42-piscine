/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:14:02 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/29 21:24:36 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int *board, int col, int row)
{
	int	i;
	int	row_diff;
	int	col_diff;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		row_diff = board[i] - row;
		col_diff = i - col;
		if (row_diff < 0)
			row_diff *= -1;
		if (col_diff < 0)
			col_diff *= -1;
		if (row_diff == col_diff)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar(int *board)
{
	int		i;
	char	output[11];

	i = 0;
	while (i < 10)
	{
		output[i] = board[i] + '0';
		i++;
	}
	output[10] = '\n';
	write(1, output, 11);
}

void	place_queens(int *board, int col, int *count)
{
	int		row;

	if (col == 10)
	{
		ft_putchar(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			place_queens(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	place_queens(board, 0, &count);
	return (count);
}
/*
#include <stdio.h>
int main(void) {
    int total_solutions = ft_ten_queens_puzzle();
    printf("Total number of solutions: %d\n", total_solutions);
    return 0;
}
*/
