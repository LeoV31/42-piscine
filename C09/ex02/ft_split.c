/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:53:34 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/02 17:05:02 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	nb_of_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if ((is_separator(str[i + 1], charset) == 1)
			&& (is_separator(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

void	ft_write_word(char *dest, char *source, char *charset)
{
	int	i;

	i = 0;
	while (is_separator(source[i], charset) == 0)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_write_split(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(str[i + j], charset) == 0)
				j++;
			split[word] = malloc(j + 1);
			ft_write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words;

	words = nb_of_words(str, charset);
	result = malloc((words + 1) * sizeof(char *));
	result[words] = 0;
	ft_write_split(result, str, charset);
	return (result);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char *str = "hello ceci est un test  ";
	char *charset = " ";
	int i;
	char **result = ft_split(str, charset);

	i = 0;
	while (result && result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
}
*/
