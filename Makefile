# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 10:43:47 by cyelena           #+#    #+#              #
#    Updated: 2021/12/07 21:14:01 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c \
		./libft/ft_isprint.c ./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c \
		./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c \
		./libft/ft_toupper.c ./libft/ft_tolower.c ./libft/ft_strchr.c ./libft/ft_strrchr.c \
		./libft/ft_strncmp.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/t_strnstr.c \
		./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c ./libft/ft_substr.c \
		./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
		./libft/ft_split.c ./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
		./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c  ./libft/ft_lstnew.c ./libft/ft_lstadd_front.c \
		./libft/ft_lstsize.c ./libft/ft_lstlast.c ./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c \
		./libft/ft_lstclear.c ./libft/ft_lstiter.c ./libft/ft_lstmap.c ./libft/ft_putstr_fd_printf.c \
		./libft/ft_putchar_fd_printf.c ./libft/ft_putp_fd_printf.c ./libft/ft_putdecimal_printf.c
HEAD = ./libft/blibft.h

OBJ = ${patsubst %.c,%.o,$(SRCS)}

D_FILES = ${patsubst %.c,%.d,$(SRCS)}

CC = gcc
FLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?
	
${OBJ} : ${HEAD} Makefile

%.o : %.c
	${CC} ${FLAGS} ${OPTFLAGS} -c $< -o $@ -MD
		
include ${wildcard ${D_FILES}}

		
clean:
	${RM} ${OBJ} ${D_FILES} 

fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
