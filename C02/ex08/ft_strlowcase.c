/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:13:37 by lviguier          #+#    #+#             */
/*   Updated: 2024/04/27 17:20:08 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*  #include <stdio.h>
int	main(int argc, char **argv)
{
	printf("Nb darguments %i\n", argc);
	printf("Argument: %s\n", argv[1]);
	char *s = ft_strupcase(argv[1]);
	printf("Resultat: %s\n", s);
}
*/
