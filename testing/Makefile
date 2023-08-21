# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 11:02:32 by fparreir          #+#    #+#              #
#    Updated: 2023/05/23 14:14:19 by fparreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= test.out
LIB		= libft/
LIBFT	= $(LIB)/libft.a
SRC		= main.c 
OBJ		= ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) -o $(NAME) $(OBJ) -L$(LIB) -lft

$(OBJ): main.c
	$(CC) -c $(SRC) -I $(LIB)includes/

run: $(NAME)
	./$(NAME)

clean:
	rm -r $(OBJ) $(NAME)

.PHONY: run clean all

