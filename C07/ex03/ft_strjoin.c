/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:27:04 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/30 20:21:26 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_totalen(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;

	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

void	ft_out(char *out, char *str, char *sep, int *k)
{
	int	j;

	j = 0;
	while (str[j])
	{
		out[*k] = str[j];
		(*k)++;
		j++;
	}
	if (sep)
	{
		j = 0;
		while (sep[j])
		{
			out[*k] = sep[j];
			(*k)++;
			j++;
		}
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*out;
	int		total_len;
	int		k;
	char	*current_sep;

	i = 0;
	k = 0;
	total_len = ft_totalen(size, strs, sep);
	out = malloc(total_len + 1);
	if (!out)
		return (NULL);
	while (i < size)
	{
		current_sep = NULL;
		if (i < size - 1)
			current_sep = sep;
		ft_out(out, strs[i], current_sep, &k);
		i++;
	}
	out[k] = '\0';
	return (out);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*sep = "  ";
	printf("%s\n", ft_strjoin(argc, argv, sep));
}
*/
