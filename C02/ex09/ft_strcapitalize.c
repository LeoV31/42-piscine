/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:13:37 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/27 19:05:56 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool	is_alphanumeric(char c)
{
	return (is_alpha(c) || (c >= '0' && c <= '9'));
}

void	capitalize_if_needed(char *c, bool new_word)
{
	if (new_word && (*c >= 'a' && *c <= 'z'))
	{
		*c -= 32;
	}
	else if (!new_word && (*c >= 'A' && *c <= 'Z'))
	{
		*c += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	bool	new_word;

	new_word = true;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			capitalize_if_needed(&str[i], new_word);
			new_word = false;
		}
		else
		{
			new_word = true;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdbool.h>
int	main(int argc, char **argv)
{
	printf("Nb darguments %i\n", argc);
	printf("Argument: %s\n", argv[1]);
	char *s = ft_strcapitalize(argv[1]);
	printf("Resultat: %s\n", s);
}
*/
