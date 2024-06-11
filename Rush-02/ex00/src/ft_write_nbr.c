/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:19:42 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 18:58:02 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_write_nbr(char *nbr, char *filepath)
{
	int		dict_size;
	char	**dict;
	int		i;

	i = 0;
	dict = ft_load_dictionary(filepath, &dict_size);
	if (dict == NULL || ft_check_dict(dict) == 1)
	{
		write(2, "Dict Error", 10);
		return ;
	}
	ft_write_nbr_word(dict, dict_size, nbr, 0);
}

void	ft_write_nbr_word(char **dict, int size, char *nbr, int numb)
{
	char	*word;

	if (ft_strlen(nbr) < 4)
	{
		if (numb == 0)
			numb = ft_atoi(nbr);
		if (numb < 20)
		{
			word = ft_find_word(dict, size, numb);
			ft_putstr(word);
			return ;
		}
		else if (numb < 100)
			ft_write_tens(dict, size, numb);
		else if (numb < 1000)
			ft_write_hundreds(dict, size, nbr, numb);
	}
	else if (ft_strlen(nbr) < 40)
		ft_write_big(dict, size, nbr);
	return ;
}

char	*find_scale(int length)
{
	if (length <= 3)
		return (NULL);
	if (length <= 6)
		return ("thousand");
	if (length <= 9)
		return ("million");
	if (length <= 12)
		return ("billion");
	if (length <= 15)
		return ("trillion");
	if (length <= 18)
		return ("quadrillion");
	return (find_scale2(length));
}

char	*find_scale2(int length)
{
	if (length <= 21)
		return ("quintillion");
	if (length <= 24)
		return ("sextillion");
	if (length <= 27)
		return ("septillion");
	if (length <= 30)
		return ("octillion");
	if (length <= 33)
		return ("nonillion");
	if (length <= 36)
		return ("decillion");
	if (length <= 39)
		return ("undecillion");
	return ("too large");
}
