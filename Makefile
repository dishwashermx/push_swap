# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2024/01/26 13:17:13 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = initall.c cleanup.c inputcheck.c \
	push_utils.c misc_utils.c \
	presort.c smallsort.c bigsort.c\
	op_swap.c op_push.c op_rotate.c op_reverse_rotate.c\
	checker_utils.c
SOURCES = $(addprefix src/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -ggdb -fsanitize=address
CC = cc
NAME = push_swap
BONUS = checker

PUSHSWAP_C = src/pushswap.c
PUSHSWAP_O = src/pushswap.o
CHECKER_C = src/checker.c
CHECKER_O = src/checker.o

LIBFT_DIR = ../libft/src
LIBFT		= $(LIBFT_DIR)/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@make -C ${LIBFT_DIR}

bonus: $(BONUS)

$(BONUS): $(OBJECTS) $(CHECKER_O)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) $(CHECKER_O) -o $(BONUS)

$(NAME): $(OBJECTS) $(PUSHSWAP_O)
	$(CC) $(FLAGS) $(PUSHSWAP_O) $(OBJECTS) -o $(NAME) $(LIBFT) 

libft:
	$(LIBFT)

clean:
	rm -f $(OBJECTS)
	rm -f $(CHECKER_O)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

.PHONY = all clean fclean re bonus