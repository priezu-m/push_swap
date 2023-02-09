# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Filename: Makefile                                                        #
#    Author:   Peru Riezu <riezumunozperu@gmail.com>                           #
#    github:   https://github.com/priezu-m                                     #
#    Licence:  GPLv3                                                           #
#    Created:  2023/01/24 18:49:56                                             #
#    Updated:  2023/02/08 16:57:17                                             #
#                                                                              #
# **************************************************************************** #

SRC =		push_swap.c basic_moves.c print_utils.c stack_init.c utils.c buffer.c sort_a.c split_b.c max.c
CC =		clang
CFLAGS =	-Wall -Wextra -Werror -flto -O0 -g3 -fsanitize=address,undefined,leak
NAME =		push_swap

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
