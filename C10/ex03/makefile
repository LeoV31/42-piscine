# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lviguier <lviguier@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 19:25:11 by lviguier          #+#    #+#              #
#    Updated: 2024/05/13 22:00:15 by lviguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_file_err.c ft_hex.c ft_putstr.c ft_write.c ft_file_parsing.c ft_putcontent.c ft_strcmp.c ft_memory.c ft_write2.c ft_write3.c
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
