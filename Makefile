# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2024/01/22 10:39:25 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = pushswap.c \
	  initall.c cleanup.c checks.c \
	  push_utils.c misc_utils.c \
	  presort.c smallsort.c bigsort.c\
	  op_swap.c op_push.c op_rotate.c op_reverse_rotate.c
LIBFT_DIR = ../libft/src
SOURCES = $(addprefix src/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -g3 -ggdb -fsanitize=address
NAME = pushswap
CC = cc

LIBFT		= $(LIBFT_DIR)/libft.a
LIBRARIES	= -L${LIBFT_DIR} -lft -lreadline -L/usr/local/opt/readline/lib

INC_RL		= -I/usr/local/opt/readline/include

all: $(NAME)

$(LIBFT):
	@make -C ${LIBFT_DIR}

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(FLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

libft:
	$(LIBFT)

clean:
	rm -f $(OBJECTS)
	# make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	@make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY = all clean fclean re