/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:04:35 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/10 14:45:14 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_comp(int a, int b)
{
	return (a - b);
}
*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	count_inc;
	int	count_dec;

	i = 0;
	count_inc = 0;
	count_dec = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			count_dec++;
		if (f(tab[i], tab[i + 1]) <= 0)
			count_inc++;
		i++;
	}
	if ((count_dec == i) || (count_inc == i))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[] = {1, 7, 5, 6, 2, 1};
	int tab2[] = {1, 2, 5, 6};

	printf("%i\n", ft_is_sort(tab, 6, ft_comp));
	printf("%i\n", ft_is_sort(tab2, 4, ft_comp));
}
*/
