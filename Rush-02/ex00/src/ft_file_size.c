/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:14:44 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 18:07:15 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_file_size(char *filepath)
{
	int		i;
	int		size;
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes;

	size = 0;
	i = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = read(fd, buf, BUF_SIZE);
	if (bytes == -1)
		return (-1);
	while (bytes > 0)
	{
		size += bytes;
		bytes = read(fd, buf, BUF_SIZE);
		if (bytes == -1)
			return (-1);
	}
	if (close(fd) == -1)
		return (-1);
	return (size);
}
