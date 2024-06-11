/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:28:42 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/13 09:30:42 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUF_SIZE 2048

# include <unistd.h>
# include <fcntl.h>

void	ft_putchar(char c, int std);
void	ft_putstr(char *str, int std, int len);
void	ft_file_content(char *filepath);
void	ft_err_message(void);

#endif
