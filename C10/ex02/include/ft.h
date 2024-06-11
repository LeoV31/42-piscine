/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:28:42 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 21:23:01 by lviguier         ###   ########.fr       */
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
# include <stdlib.h>

typedef int	t_bool;

typedef struct s_state
{
	char	*status;
	t_bool	error;
}	t_state;

void	ft_putchar(char c);
void	ft_putstr(char *str, int len);
void	ft_file_content(t_state *state, char *filepath, int nb_bytes);
void	ft_write_stdin(void);
void	ft_write_err(char *error);
t_bool	valid_nbr(char *argv);
void	invalid_msg(t_state *state, char *argv);
int		ft_atoi(char *str);
void	ft_sep(char *filepath);
void	main_helper(int argc, char **argv, t_state *state);
void	missing_arg(t_state *state);
int		ft_file_size(t_state *state, char *filepath);
int		ft_file_size_err(t_state *state, char *filepath);
void	ft_file_content_err(t_state *state, char *filepath);
void	ft_err(t_state *state, char *filepath);
void	ft_write_stdin_with_bytes(int nb_bytes);
char	*ft_memcpy(char *dest, char *src, int n);
void	ft_write_stdin_content(char **content, int *total_read);
t_bool	file_exists(char *filename);
t_bool	file_exists_before(char **argv_copy, char **argv);

#endif
