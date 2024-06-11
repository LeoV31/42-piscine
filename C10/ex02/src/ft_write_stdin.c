/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_std.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:04:18 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 15:53:21 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_write_stdin(void)
{
	char	a;

	while (read(STDIN, &a, 1))
		;
}

void	ft_write_stdin_with_bytes(int nb_bytes)
{
	char	*content;
	int		total_read;

	content = NULL;
	total_read = 0;
	ft_write_stdin_content(&content, &total_read);
	if (content != NULL)
	{
		content[total_read] = '\0';
		if (nb_bytes > total_read)
			ft_putstr(content, total_read);
		else
			ft_putstr(content + total_read - nb_bytes, nb_bytes);
		free(content);
	}
}

void	ft_write_stdin_content(char **content, int *total_read)
{
	char	buf[BUF_SIZE];
	char	*new_content;
	int		bytes_read;

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

char	*ft_memcpy(char *dest, char *src, int n)
{
	int		i;

	i = -1;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (++i < n)
		dest[i] = src[i];
	return (dest);
}
