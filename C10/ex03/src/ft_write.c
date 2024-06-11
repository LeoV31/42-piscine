/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:09:00 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/16 10:59:09 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_write_err(char *error)
{
	while (*error)
		write(2, error++, 1);
}

void	ft_write_stdin(int canon)
{
	unsigned char	*content;
	int				total_read;

	content = NULL;
	total_read = 0;
	ft_write_stdin_content(&content, &total_read);
	if (content != NULL)
	{
		content[total_read] = '\0';
		ft_write_hexdump_helper(total_read, canon, content);
		free(content);
	}
}

void	ft_write_stdin_content(unsigned char **content, int *total_read)
{
	unsigned char	buf[BUF_SIZE];
	unsigned char	*new_content;
	int				bytes_read;

	bytes_read = read(STDIN_FILENO, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		new_content = malloc(*total_read + bytes_read + 1);
		if (new_content == NULL)
		{
			free(*content);
			return ;
		}
		if (*content != NULL)
			ft_memcpy(new_content, *content, *total_read);
		ft_memcpy(new_content + *total_read, buf, bytes_read);
		*total_read += bytes_read;
		free(*content);
		*content = new_content;
		bytes_read = read(STDIN_FILENO, buf, BUF_SIZE);
	}
}

unsigned char	*ft_write_hexdump(char **argv, char *exec,
									char *filepath, int *size)
{
	unsigned char	*buf;

	buf = (unsigned char *)0;
	*size = ft_file_size(argv, exec, filepath);
	if (*size == -1)
		return ((unsigned char *)0);
	buf = ft_file_content(exec, filepath, buf, *size);
	if (buf == NULL)
		return ((unsigned char *)0);
	return (buf);
}

unsigned char	*init_hexdump(int *i, int *repeated,
			unsigned long long *pos, int *line_size)
{
	unsigned char	*prev_line;

	*i = 0;
	*repeated = 0;
	*pos = 0;
	*line_size = 0;
	prev_line = malloc(16);
	return (prev_line);
}
