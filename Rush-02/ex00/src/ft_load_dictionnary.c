/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_dictionnary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:17:05 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 19:37:16 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

char	**ft_load_dictionary(char *filepath, int *dict_size)
{
	int		size;
	char	**dict;
	char	*buf;

	buf = read_file_to_buffer(filepath, &size);
	if (buf == NULL)
		return (NULL);
	dict = ft_buf_to_dict(buf, dict_size);
	free(buf);
	return (dict);
}

char	*read_file_to_buffer(char *filepath, int *size)
{
	int		fd;
	char	*buf;
	int		bytes;

	*size = ft_file_size(filepath);
	if (*size == -1)
		return (NULL);
	buf = malloc(sizeof(char) * (*size + 1));
	if (buf == NULL)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (read_file_helper(buf));
	bytes = read(fd, buf, *size);
	if (bytes == -1)
	{
		free(buf);
		close(fd);
		return (NULL);
	}
	if (close(fd) == -1)
		return (read_file_helper(buf));
	buf[*size] = '\0';
	return (buf);
}

char	*read_file_helper(char *buf)
{
	free(buf);
	return (NULL);
}

char	**ft_buf_to_dict(char *buf, int *dict_size)
{
	int		lines;
	char	**dict;
	char	*p;
	char	*line_start;

	lines = 0;
	p = buf;
	while (*p)
	{
		if (*p == '\n')
			lines++;
		p++;
	}
	dict = malloc(sizeof(char *) * lines);
	if (!dict)
		return (NULL);
	line_start = buf;
	p = buf;
	ft_buf_to_dict_helper(dict, line_start, p);
	*dict_size = lines;
	return (dict);
}

void	ft_buf_to_dict_helper(char **dict, char *line_start, char *p)
{
	int	idx;

	idx = 0;
	while (*p)
	{
		if (*p == '\n')
		{
			*p = '\0';
			dict[idx] = ft_strdup(line_start, p - line_start);
			line_start = p + 1;
			idx++;
		}
		p++;
	}
}
