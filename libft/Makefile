# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 09:54:51 by ghwa              #+#    #+#              #
#    Updated: 2023/12/19 14:49:19 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES = ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
	  ft_striteri.c ft_strmapi.c \
	  ft_itoa.c ft_atol.c ft_atoi.c \
	  ft_strjoin.c ft_strtrim.c ft_substr.c ft_split.c \
	  ft_strrchr.c ft_strdup.c ft_strlen.c ft_dupiarray.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_isdigitarray.c\
	  ft_memchr.c ft_memset.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_bzero.c ft_calloc.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlcat.c ft_strlcpy.c \
	  ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strendcmp.c ft_countchr.c \
	  ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c \
	  ft_printf.c ft_printf_utils.c \
	  ft_get_next_line.c ft_get_next_line_utils.c
OBJ = ${SRC:.c=.o}
SRC = $(addprefix src/, $(CFILES))
FLAGS = -c -Wall -Werror -g3 -Wextra -I.
INC_DIR = .
GCC = gcc
MAKELIB	= ar rc

all: $(NAME)

${NAME}:	${OBJ}
	@${MAKELIB} ${NAME} ${OBJ}

.c.o:
	@${GCC} ${CFLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY = all clean fclean re bonus
