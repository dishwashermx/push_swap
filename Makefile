# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:20:07 by ghwa              #+#    #+#              #
#    Updated: 2023/12/14 17:11:11 by ghwa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = pushswap.c checks.c initall.c misc_utils.c push_utils.c presort.c op_swap.c op_push.c op_rotate.c op_reverse_rotate.c smallsort.c
SOURCES = $(addprefix Sources/, $(CFILES))
OBJECTS = ${SOURCES:.c=.o}
FLAGS = -Wall -Werror -Wextra -g3 -ggdb -fsanitize=address
NAME = push_swap
CC = cc

all: $(LIBFT) $(NAME)

all: $(NAME)

$(NAME): $(OBJECTS)
	CC $(FLAGS) $(FLAGS) $(OBJECTS) ../libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re