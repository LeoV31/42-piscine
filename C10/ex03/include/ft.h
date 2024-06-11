/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:36:01 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/15 22:09:39 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

/* 2^14 + 2^13 + 2^12 + 2^10 = 29696 */
# define BUF_SIZE 29696

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdlib.h>

unsigned char	*ft_write_hexdump(char **argv, char *exec,
					char *filepath, int *size);
unsigned char	*ft_file_content(char *exec, char *filepath,
					unsigned char *buf, int size);
int				ft_file_size(char **argv, char *exec, char *filepath);
void			ft_err(char *exec, char *filepath);
int				ft_file_size_err(char *exec, char *filepath);
unsigned char	*ft_file_content_err(char *exec, char *filepath);
void			ft_write_err(char *error);
char			*ft_strcpy(char *dest, char *src);
void			ft_get_hex(unsigned long long pos, int prev);
void			ft_putstr(char *str, int size);
void			ft_putpos_hex(unsigned long long pos, int canon);
void			ft_write_stdin(int canon);
int				ft_strcmp(char *s1, char *s2);
void			ft_putcontent(unsigned char *buf, int line_size, int canon);
void			ft_putcontent_right(unsigned char *buf, int line_size);
void			ft_write_hexdump_helper(int size, int canon,
					unsigned char *buf);
unsigned char	*ft_memcpy(unsigned char *dest, unsigned char *src, int n);
int				ft_memcmp(unsigned char *s1, unsigned char *s2, int n);
unsigned char	*init_hexdump(int *i, int *repeated,
					unsigned long long *pos, int *line_size);
void			ft_write_hexdump_helper2(int line_size, int canon,
					unsigned char *buf, int i);
void			ft_write_hexdump_helper3(int *repeated);
void			ft_write_hexdump_helper4(int i, int size, int *line_size);
int				ft_write_hexdump_helper5(int line_size,
					unsigned char *prev_line, unsigned char *buf, int *i);
void			ft_write_hexdump_helper6(int *repeated,
					unsigned long long pos, int canon);
void			ft_write_hexdump_helper7(int repeated,
					unsigned long long pos, int canon);
void			ft_write_combine_arg(char **argv, char *exec, int canon);
int				ft_tablen(char **argv);
unsigned char	*ft_strcat(unsigned char *dest,
					unsigned char *src, int *size, int i);
void			ft_write_stdin_content(unsigned char **content,
					int *total_read);
int				ft_last_error(char **argv, char *filepath);

#endif
