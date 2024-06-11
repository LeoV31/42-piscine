/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aportero <aportero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:37:08 by aportero          #+#    #+#             */
/*   Updated: 2024/04/27 17:49:03 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int x, int row, int col, int y)
{
	char	var;

	while (col <= x)
	{
		var = (row == y && col == x && x != 1 && y != 1);
		if ((row == 1 && col == 1) || var)
			ft_putchar('A');
		else if ((row == y && col == 1) || (row == 1 && col == x))
			ft_putchar('C');
		else if (row == 1 || col == 1 || row == y || col == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		col++;
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	while (row <= y)
	{
		col = 1;
		print(x, row, col, y);
		ft_putchar('\n');
		row++;
	}
}
