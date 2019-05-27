# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 14:34:56 by ramory-l          #+#    #+#              #
#    Updated: 2019/05/27 16:57:05 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

EXE = test

SRC_SEARCH = src/*.c \
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
	@gcc -c $< -o $@ $(IMFLAGS) $(HEADERS) -g

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
	make re
	@rm -rf $(EXE)
	@gcc -o test main.c $(HEADERS) -L . -lftprintf