/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:18:13 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/07 19:25:22 by lviguier         ###   ########.fr       */
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
	argv++;
	while (*argv)
		ft_file_content(&state, *argv++);
	return (state.error);
}
