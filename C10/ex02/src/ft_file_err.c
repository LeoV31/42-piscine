/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:45:55 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 21:31:28 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_file_size_err(t_state *state, char *filepath)
{
	ft_err(state, filepath);
	return (-1);
}

void	ft_file_content_err(t_state *state, char *filepath)
{
	ft_err(state, filepath);
	return ;
}

void	invalid_msg(t_state *state, char *argv)
{
	ft_write_err(basename(state->status));
	ft_write_err(": illegal offset -- ");
	ft_write_err(argv);
	ft_write_err("\n");
}

void	missing_arg(t_state *state)
{
	ft_write_err(basename(state->status));
	ft_write_err(": option requires an argument -- c");
	ft_write_err("\n");
	ft_write_err("usage: ");
	ft_write_err(basename(state->status));
	ft_write_err(" [-F | -f | -r] [-q] ");
	ft_write_err("[-b # | -c # | -n #] [file ...]\n");
}
