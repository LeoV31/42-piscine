/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:04:51 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/28 16:22:21 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*d;
	char	*s;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		d = str;
		s = to_find;
		while (*s != '\0' && *d == *s)
		{
			d++;
			s++;
		}
		if (*s == '\0')
			return (str);
		str++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "hello je mappelle leo et toi";
	char s2[] = "leo";
	printf("%s\n", ft_strstr(s1, s2));
	return 0;
}
*/
