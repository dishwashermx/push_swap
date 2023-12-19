# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2023/12/19 17:08:59 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = pushswap.c \
	  checks.c \
	  initall.c \
	  push_utils.c misc_utils.c \
	  presort.c smallsort.c \
	  op_swap.c op_push.c op_rotate.c op_reverse_rotate.c
LIBFT_DIR = ../libft/src
SOURCES = $(addprefix src/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -g3 -ggdb -fsanitize=address
NAME = push_swap
CC = cc

LIBFT		= $(LIBFT_DIR)/libft.a
LIBRARIES	= -L${LIBFT_DIR} -lft -lreadline -L/usr/local/opt/readline/lib

INC_RL		= -I/usr/local/opt/readline/include

all: $(NAME)

$(LIBFT):
	@make -C ${LIBFT_DIR}

$(NAME): $(LIBFT) $(OBJECTS)
	CC $(FLAGS) $(FLAGS) $(OBJECTS) ../libft/inc/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

libft:
	$(LIBFT)

clean:
	rm -f $(OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY = all clean fclean re