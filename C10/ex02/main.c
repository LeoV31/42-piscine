/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:18:13 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 21:31:11 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc == 1)
	{
		ft_write_stdin();
		return (0);
	}
	state.status = *argv;
	state.error = FALSE;
	if (argc == 2)
	{
		missing_arg(&state);
		return (state.error);
	}
	if (!valid_nbr(*(argv + 2)))
	{
		invalid_msg(&state, *(argv + 2));
		return (state.error);
	}
	else if (argc == 3)
		ft_write_stdin_with_bytes(ft_atoi(argv[2]));
	else
		main_helper(argc, argv, &state);
	return (state.error);
}

void	main_helper(int argc, char **argv, t_state *state)
{
	int		nb_bytes;
	char	**argv_copy;

	nb_bytes = ft_atoi(*(argv + 2));
	argv += 3;
	argv_copy = argv;
	while (*argv)
	{
		if (file_exists(*argv))
		{
			if (file_exists_before(argv_copy, argv))
				ft_putstr("\n", 0);
			if (argc > 4)
				ft_sep(*argv);
			ft_file_content(state, *argv, nb_bytes);
		}
		else
			ft_err(state, *argv);
		argv++;
	}
}

t_bool	file_exists_before(char **argv_copy, char **argv)
{
	while (argv_copy < argv)
	{
		if (file_exists(*argv_copy))
			return (TRUE);
		argv_copy++;
	}
	return (FALSE);
}

t_bool	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

t_bool	valid_nbr(char *arg)
{
	while (*arg)
	{
		if (!(*arg >= 48 && *arg <= 57))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}
