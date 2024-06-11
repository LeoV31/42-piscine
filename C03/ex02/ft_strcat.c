/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:04:51 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/28 15:52:29 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	s;
	unsigned int	d;

	s = 0;
	d = 0;
	while (dest[d] != '\0')
		d++;
	while (src[s] != '\0')
	{
		dest[d + s] = src[s];
		s++;
	}
	dest[d + s] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "hello";
	char s2[] = "he";

	ft_strcat(s1, s2);
	printf("%s\n", s1);
	return 0;
}
*/
