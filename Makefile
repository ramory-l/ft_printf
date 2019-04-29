# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramory-l <ramory-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 14:34:56 by ramory-l          #+#    #+#              #
#    Updated: 2019/04/29 15:13:06 by ramory-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC_SEARCH = src/*.c main.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I libft/include

IMFLAGS = -Wall -Wextra -Werror

LFT = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ) libft
	gcc $(OBJ) -o $@ $(LFT)

%.o: %.c
	gcc -c $< -o $@ $(IMFLAGS) $(HEADERS)

.PHONY: libft
libft:
	make -C libft

.PHONY: clean
clean:
	rm -Rf $(OBJ)
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -Rf $(NAME)
	make fclean -C libft

.PHONY: re
re: fclean all
