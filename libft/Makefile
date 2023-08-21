# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fparreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:45:36 by fparreir          #+#    #+#              #
#    Updated: 2023/04/23 11:18:50 by fparreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_split.c ft_strrchr.c ft_strdup.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c  \
	  ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strtrim.c ft_substr.c  \
	  ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: 
	$(CC) $(CFLAGS) -c $(SRC) $(BONUS_SRC)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
  
$(NAME): 
	$(CC) $(CFLAGS) -c $(SRC)	
	ar rcs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
