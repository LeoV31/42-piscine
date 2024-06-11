/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:04:51 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/28 13:24:09 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else if (s1[i] == '\0')
	{
		return (-s2[i]);
	}
	else if (s2[i] == '\0')
	{
		return (s1[i]);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "hello";
	char s2[] = "he";
	printf("%d\n", ft_strcmp(s1, s2));
}
*/
