/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:13:13 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:39 by lviguier         ###   ########.fr       */
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

void	ft_sep(char *filepath)
{
	ft_putstr("==> ", 0);
	ft_putstr(filepath, 0);
	ft_putstr(" <==", 0);
	ft_putstr("\n", 0);
}

void	ft_file_content(t_state *state, char *filepath, int nb_bytes)
{
	int		fd;
	char	*buf;
	int		bytes;
	int		size;

	size = ft_file_size(state, filepath);
	if (size == -1)
		return ;
	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return ;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ft_file_content_err(state, filepath));
	bytes = read(fd, buf, size);
	if (bytes == -1)
		return (ft_file_content_err(state, filepath));
	if (close(fd) == -1)
		return (ft_file_content_err(state, filepath));
	buf[size] = '\0';
	if (nb_bytes > size)
		ft_putstr(&buf[0], size);
	else
		ft_putstr(&buf[size - nb_bytes], nb_bytes);
}

int	ft_file_size(t_state *state, char *filepath)
{
	int		size;
	int		bytes;
	char	buf[BUF_SIZE];
	int		i;
	int		fd;

	size = 0;
	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ft_file_size_err(state, filepath));
	bytes = read(fd, buf, BUF_SIZE);
	while (bytes > 0)
	{
		size += bytes;
		bytes = read(fd, buf, BUF_SIZE);
	}
	if (bytes == -1)
		return (ft_file_size_err(state, filepath));
	if (close(fd) == -1)
		return (-1);
	return (size);
}
