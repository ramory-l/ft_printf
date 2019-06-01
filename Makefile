# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 14:34:56 by ramory-l          #+#    #+#              #
#    Updated: 2019/06/01 16:32:33 by ramory-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

EXE = test

SRC_SEARCH = src/*.c \
			 src/ft_manage_percent/*.c \
			 src/ft_manage_percent/ft_print_number/*.c \
			 libft/src/*.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I libft/include

IMFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@gcc -c $< -o $@ $(HEADERS) -g

.PHONY: clean
clean:
	@rm -Rf $(OBJ)

.PHONY: fclean
fclean: clean
	@rm -Rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test:
	@rm -rf $(EXE)
	@gcc -o test main.c $(HEADERS) -L . -lftprintf -g