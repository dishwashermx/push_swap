# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2024/01/23 15:15:02 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = initall.c cleanup.c checks.c \
	push_utils.c misc_utils.c \
	presort.c smallsort.c bigsort.c\
	op_swap.c op_push.c op_rotate.c op_reverse_rotate.c
SOURCES = $(addprefix src/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -g3 -ggdb -fsanitize=address
CC = cc
NAME = pushswap
BONUS = checker

PUSHSWAP_C = ./src/pushswap.c
PUSHSWAP_O = ./src/pushswap.o
CHECKER_C = ./src/checker.c
CHECKER_O = ./src/checker.o

LIBFT_DIR = ../libft/src
LIBFT		= $(LIBFT_DIR)/libft.a
LIBRARIES	= -L${LIBFT_DIR} -lft -lreadline -L/usr/local/opt/readline/lib

INC_RL		= -I/usr/local/opt/readline/include

all: $(NAME)

bonus: $(BONUS)

$(LIBFT):
	@make -C ${LIBFT_DIR}

$(BONUS): $(LIBFT) $(OBJECTS) $(CHECKER_O)
	$(CC) $(FLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) $(CHECKER_O) -o $(BONUS)

$(NAME): $(LIBFT) $(OBJECTS) $(PUSHSWAP_O)
	$(CC) $(FLAGS) $(FLAGS) $(PUSHSWAP_O) $(OBJECTS) $(LIBFT) -o $(NAME)

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