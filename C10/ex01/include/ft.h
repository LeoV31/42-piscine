/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:28:42 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/07 19:17:49 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

/* 2^14 + 2^13 + 2^12 + 2^10 = 29696 */
# define BUF_SIZE 29696
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>

typedef int	t_bool;

typedef struct s_state
{
	char	*status;
	t_bool	error;
}	t_state;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_file_content(t_state *state, char *filepath);
void	ft_write_stdin(void);
void	ft_write_err(char *error);

#endif
