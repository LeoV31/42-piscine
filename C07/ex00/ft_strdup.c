/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:43:28 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/30 17:13:31 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	copy[i] = '\0';
	while (i != 0)
	{
		i--;
		copy[i] = src[i];
	}
	return (copy);
}
/*
#include <stdio.h>
int	main(void)
{
	char *src = "hello";

	printf("%s\n", ft_strdup(src));
}
*/
