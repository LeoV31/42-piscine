/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:25:19 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/07 18:34:03 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_write_err(char *error)
{
	while (*error)
		write(STDERR, error++, 1);
}
