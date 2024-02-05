# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2024/02/05 09:44:37 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = initall.c cleanup.c inputcheck.c \
	push_utils.c misc_utils.c \
	presort.c smallsort.c bigsort.c\
	op_swap.c op_push.c op_rotate.c op_reverse_rotate.c
SOURCES = $(addprefix src/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -ggdb -g3
CC = cc
NAME = push_swap
BONUS = checker

PUSHSWAP_C = src/pushswap.c
PUSHSWAP_O = src/pushswap.o
CHECKER_C = src/checker.c
CHECKER_O = src/checker.o

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

bonus: $(BONUS)

lib:
	@make re -C ${LIBFT_DIR}

$(BONUS): $(OBJECTS) $(CHECKER_O)
	$(CC) $(FLAGS) $(LIBFT) $(OBJECTS) $(CHECKER_O) -o $(BONUS)

$(NAME): $(OBJECTS) $(PUSHSWAP_O)
	$(CC) $(FLAGS) $(PUSHSWAP_O) $(LIBFT) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(CHECKER_O)
	rm -f $(PUSHSWAP_O)

fclean: clean
	rm -f $(BONUS)
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re bonus lib