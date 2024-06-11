/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:38:25 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/16 09:42:54 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft.h"

int	main(int argc, char **argv)
{
	int		canon;
	char	*exec;

	canon = 0;
	exec = *argv;
	if (argc == 2 && ft_strcmp(argv[1], "-C") == 0)
	{
		argc = 1;
		canon = 1;
	}
	if (argc == 1)
	{
		ft_write_stdin(canon);
		return (0);
	}
	argv++;
	if (ft_strcmp(*argv, "-C") == 0)
	{
		argv++;
		canon = 1;
	}
	ft_write_combine_arg(argv, exec, canon);
	return (0);
}

void	ft_write_combine_arg(char **argv, char *exec, int canon)
{
	unsigned char	*allarg;
	int				*size;
	int				i;
	int				total_len;

	size = malloc(ft_tablen(argv) * sizeof(int));
	i = -1;
	total_len = 0;
	while (argv[++i])
	{
		if (ft_write_hexdump(argv, exec, argv[i],
				&size[i]) == (unsigned char *)0)
			size[i] = 0;
		total_len += size[i];
	}
	allarg = malloc(total_len);
	i = -1;
	while (argv[++i])
	{
		if (size[i] > 0)
			ft_strcat(allarg, ft_write_hexdump(argv, exec,
					argv[i], &size[i]), size, i);
	}
	if (total_len > 0)
		ft_write_hexdump_helper(total_len, canon, allarg);
}

int	ft_tablen(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

unsigned char	*ft_strcat(unsigned char *dest, unsigned char *src,
					int *size, int i)
{
	int	j;
	int	allarg_len;

	j = 0;
	allarg_len = 0;
	while (j < i)
	{
		allarg_len += size[j];
		j++;
	}
	j = 0;
	while (j < size[i])
	{
		if (i == 0)
			dest[j] = src[j];
		else
			dest[allarg_len + j] = src[j];
		j++;
	}
	return (dest);
}
