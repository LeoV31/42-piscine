/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:29:39 by lviguier          #+#    #+#             */
/*   Updated: 2024/05/12 20:13:04 by lviguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUF_SIZE 29696

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_check_nbr(char *str);
int		ft_atoi(char *str);
void	ft_write_nbr(char *nbr, char *filepath);
char	**ft_load_dictionary(char *filepath, int *dict_size);
int		ft_file_size(char *filepath);
char	*ft_strdup(char *src, int len);
void	ft_putstr(char *str);
void	ft_write_nbr_word(char **dict, int size, char *nbr, int numb);
void	ft_write_tens(char **dict, int size, int numb);
void	ft_write_hundreds(char **dict, int size, char *nbr, int numb);
void	ft_write_big(char **dict, int size, char *nbr);
void	ft_write_part(char **dict, int size, char *scale, char *nbr);
char	*ft_find_word(char **dict, int size, int nbr);
char	*ft_find_word_str(char **dict, int size, char *nbr);
char	*ft_find_word_helper(char *str);
char	*find_scale(int length);
char	*find_scale2(int length);
char	*ft_atoi_str(char *str);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_error(void);
char	**ft_buf_to_dict(char *buf, int *dict_size);
int		ft_check_dict(char **dict);
char	*read_file_to_buffer(char *filepath, int *size);
char	*read_file_helper(char *buf);
void	ft_buf_to_dict_helper(char **dict, char *line_start, char *p);
int		ft_check_dict_helper(char **dict, int i, int j);
char	*ft_atoi_str_helper(char *str);

#endif
