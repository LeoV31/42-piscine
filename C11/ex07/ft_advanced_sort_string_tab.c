/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:46:25 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/10 12:25:32 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_comp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] == b[i] && (a[i] != 0 && b[i] != 0))
		i++;
	return (a[i] - b[i]);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_tablen(tab);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	i = 0;
	ft_advanced_sort_string_tab(argv, &ft_comp);
	while (i < ft_tablen(argv))
	{
		printf("%s\n", argv[i]);
		i++;
	}
}
*/
