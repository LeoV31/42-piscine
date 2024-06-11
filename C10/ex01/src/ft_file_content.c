/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:13:13 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/07 19:26:36 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_err(t_state *state, char *filepath)
{
	if (!errno)
		return ;
	ft_write_err(basename(state->status));
	ft_write_err(": ");
	ft_write_err(filepath);
	ft_write_err(": ");
	ft_write_err(strerror(errno));
	ft_write_err("\n");
	if (!state->error)
		state->error = FALSE;
}

void	ft_file_content(t_state *state, char *filepath)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		bytes;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_err(state, filepath);
		return ;
	}
	bytes = read(fd, buf, BUF_SIZE);
	while (bytes)
	{
		if (bytes == -1)
		{
			ft_err(state, filepath);
			break ;
		}
		buf[bytes] = '\0';
		ft_putstr(buf);
		bytes = read(fd, buf, BUF_SIZE);
	}
	if (close(fd) == -1)
		ft_err(state, filepath);
}
