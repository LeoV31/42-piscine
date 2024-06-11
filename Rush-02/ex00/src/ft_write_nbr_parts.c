/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr_parts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:57:04 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 20:56:09 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_write_tens(char **dict, int size, int numb)
{
	char	*word;
	int		ones;
	int		tens;

	if (numb % 10 == 0)
	{
		word = ft_find_word(dict, size, numb);
		ft_putstr(word);
	}
	else
	{
		tens = numb / 10 * 10;
		ones = numb % 10;
		ft_putstr(ft_find_word(dict, size, tens));
		if (ones)
		{
			write(1, " ", 1);
			ft_putstr(ft_find_word(dict, size, ones));
		}
	}
}

void	ft_write_hundreds(char **dict, int size, char *nbr, int numb)
{
	int	hundreds;
	int	rest;

	hundreds = numb / 100;
	rest = numb % 100;
	ft_putstr(ft_find_word(dict, size, hundreds));
	ft_putstr(" hundred");
	if (rest)
	{
		write(1, " ", 1);
		ft_write_nbr_word(dict, size, nbr, rest);
	}
}

void	ft_write_big(char **dict, int size, char *nbr)
{
	char	*scale;
	char	part[100];
	int		first_part_size;

	scale = find_scale(ft_strlen(nbr));
	while (scale)
	{
		if (ft_strlen(nbr) % 3 == 0)
			first_part_size = 3;
		else
			first_part_size = ft_strlen(nbr) % 3;
		ft_strncpy(part, nbr, first_part_size);
		part[first_part_size] = '\0';
		ft_write_nbr_word(dict, size, part, 0);
		nbr += first_part_size;
		while (*nbr == '0')
			nbr++;
		ft_write_part(dict, size, scale, nbr);
		if (ft_strlen(nbr) == 0 || *nbr == '\0')
			break ;
		scale = find_scale(ft_strlen(nbr));
	}
}

void	ft_write_part(char **dict, int size, char *scale, char *nbr)
{
	ft_putstr(" ");
	ft_putstr(scale);
	if (ft_strlen(nbr) > 0)
	{
		ft_putstr(" ");
		if (ft_strlen(nbr) < 4)
			ft_write_nbr_word(dict, size, nbr, 0);
	}
}
