/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:04:51 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/28 16:55:59 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d;
	unsigned int	dest_len;
	unsigned int	src_len;

	d = 0;
	src_len = 0;
	dest_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dest[dest_len] != '\0')
		dest_len++;
	if (dest_len >= size)
		return (src_len + size);
	while (((dest_len + d) < (size - 1)) && src[d] != '\0')
	{
		dest[dest_len + d] = src[d];
		d++;
	}
	dest[dest_len + d] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "hello";
	char s2[] = " jemapelle";
	unsigned int i = 3;
	ft_strlcat(s1, s2, i);
	printf("%s\n", s1);
	return 0;
}
*/
