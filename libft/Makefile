# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/25 17:37:01 by ramory-l          #+#    #+#              #
#    Updated: 2019/04/12 15:25:35 by ramory-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_SEARCH = src/*.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

INCLUDES = -I include

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror $(INCLUDES)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean:	clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
