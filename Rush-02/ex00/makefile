# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 19:53:49 by lviguier          #+#    #+#              #
#    Updated: 2024/05/12 20:00:52 by lviguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putstr.c ft_atoi.c ft_strdup.c ft_atoi_str.c ft_strlen.c ft_check_dict.c ft_strncpy.c ft_check_nbr.c ft_write_nbr.c ft_file_size.c ft_write_nbr_parts.c ft_find.c ft_load_dictionnary.c
SRC_DIR = src/
INC_DIR = include/
SRCS = ${addprefix ${SRC_DIR},${SRC}} main.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -I${INC_DIR} $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
