/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:18:22 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 13:08:03 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

char	*ft_find_word(char **dict, int size, int nbr)
{
	int		i;
	char	*str;

	i = 0;
	while (i < size)
	{
		if (ft_atoi(dict[i]) == nbr)
		{
			str = ft_find_word_helper(dict[i]);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_find_word_helper(char *str)
{
	int		i;
	char	*word;

	i = 0;
	word = str;
	while (*word != ':' && *word)
		word++;
	word++;
	while (*word == ' ')
		word++;
	while (word[i])
	{
		if (word[i] < 32 || word[i] > 126)
			word[i] = '\0';
		i++;
	}
	return (word);
}

char	*ft_find_word_str(char **dict, int size, char *nbr)
{
	int		i;
	char	*copy;

	i = 0;
	while (i < size)
	{
		copy = ft_strdup(dict[i], ft_strlen(dict[i]));
		if (ft_atoi_str(copy) == nbr)
		{
			return (ft_find_word_helper(dict[i]));
		}
		i++;
	}
	return (NULL);
}
