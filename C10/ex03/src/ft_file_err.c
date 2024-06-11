/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:18:05 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 20:01:02 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

void	ft_err(char *exec, char *filepath)
{
	if (!errno)
		return ;
	ft_write_err(basename(exec));
	ft_write_err(": ");
	ft_write_err(filepath);
	ft_write_err(": ");
	ft_write_err(strerror(errno));
	ft_write_err("\n");
}

int	ft_file_size_err(char *exec, char *filepath)
{
	ft_err(exec, filepath);
	return (-1);
}

unsigned char	*ft_file_content_err(char *exec, char *filepath)
{
	ft_err(exec, filepath);
	return (NULL);
}
