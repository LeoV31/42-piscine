/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_std.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:04:18 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/07 15:33:35 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_write_stdin(void)
{
	char	buf[BUF_SIZE];
	int		bytes_read;

	bytes_read = read(STDIN, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(STDOUT, buf, bytes_read);
		bytes_read = read(STDIN, buf, BUF_SIZE);
	}
}
