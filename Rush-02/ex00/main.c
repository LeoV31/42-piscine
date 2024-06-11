/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:28:52 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 17:09:36 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft.h"

int	main(int argc, char **argv)
{
	char	*nbr;

	if (argc < 2 || argc > 3)
		return (ft_error());
	else if (argc == 2)
	{
		nbr = ft_atoi_str(argv[1]);
		if (!(*nbr) || ft_strlen(nbr) > 39)
			return (ft_error());
		ft_write_nbr(nbr, "./src/numbers.dict");
		write(1, "\n", 1);
	}
	else if (argc == 3)
	{
		nbr = ft_atoi_str(argv[2]);
		if (!(*nbr) || ft_strlen(nbr) > 39)
			return (ft_error());
		ft_write_nbr(nbr, argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
