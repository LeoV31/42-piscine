/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:20:39 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/05 15:19:23 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		*to_numbers(char *str);
void	write_solution(int tab[4][4]);
int		check_row_col(int tab[4][4], int row, int col, int nbr);
int		check_inputs(int tab[4][4], int inputs[16], int pos);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) != 31)
		return (1);
	return (0);
}

int	solve(int tab[4][4], int inputs[16], int pos)
{
	int	nbr;
	int	row;
	int	col;

	nbr = 1;
	if (pos == 16)
		return (1);
	while (nbr <= 4)
	{
		row = pos / 4;
		col = pos % 4;
		if (check_row_col(tab, row, col, nbr) == 1)
		{
			tab[row][col] = nbr;
			if (check_inputs(tab, inputs, pos) == 1)
				if (solve(tab, inputs, pos + 1) == 1)
					return (1);
			tab[row][col] = 0;
		}
		nbr++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*inputs;
	int	tab[4][4];
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			tab[i][j] = 0;
	}
	if (check_args(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	inputs = to_numbers(argv[1]);
	if (*inputs != -1 && solve(tab, inputs, 0) == 1)
		write_solution(tab);
	else
		write(1, "Error\n", 6);
	return (0);
}
