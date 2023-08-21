# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:51:20 by fparreir          #+#    #+#              #
#    Updated: 2023/05/22 16:34:21 by fparreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
OUT_NAME		= printf.out

CC				= cc
CFLAGS			= -Wall -Werror -Wextra

OBJDIR			= build/
INCDIR			= includes/
SRC				= src/

SOURCES			= $(SRC)ft_printf.c $(SRC)put_utils.c $(SRC)utils.c
SOURCES_MAIN	= $(SOURCES) main.c
OBJECTS			= ${SOURCES:.c=.o}
OBJECTS			= $(subst $(SRC),$(OBJDIR), $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJECTS)
	@echo "Linking Objects into Library"
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Done!"

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJECTS): 
	@echo "compiling object files"
	@$(CC) $(SOURCES) -c $(CFLAGS)
	@mv *.o $(OBJDIR) 

clean:
	@rm -rf $(OBJDIR)
  
fclean: clean 
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
