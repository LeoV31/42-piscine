/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:19:09 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/16 09:48:48 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

unsigned char	*ft_file_content(char *exec, char *filepath,
					unsigned char *buf, int size)
{
	int	fd;
	int	bytes;

	if (size == -1)
		return (NULL);
	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (ft_file_content_err(exec, filepath));
	bytes = read(fd, buf, size);
	if (bytes == -1)
		return (ft_file_content_err(exec, filepath));
	if (close(fd) == -1)
		return (ft_file_content_err(exec, filepath));
	buf[size] = '\0';
	return (buf);
}

int	ft_file_size(char **argv, char *exec, char *filepath)
{
	int				size;
	int				bytes;
	unsigned char	buf[BUF_SIZE];
	int				i;
	int				fd;

	size = 0;
	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_err(exec, filepath);
	bytes = read(fd, buf, BUF_SIZE);
	while (bytes > 0)
	{
		size += bytes;
		bytes = read(fd, buf, BUF_SIZE);
	}
	if (bytes == -1 && ft_last_error(argv, filepath))
		return (ft_file_size_err(exec, filepath));
	if (close(fd) == -1)
		return (-1);
	return (size);
}

int	ft_last_error(char **argv, char *filepath)
{
	while (*argv != filepath)
		argv++;
	argv++;
	if (*argv)
		return (0);
	return (1);
}
