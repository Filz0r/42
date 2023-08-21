NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
DFLAGS	= $(CFLAGS) -g3
FFLAGS	= $(DFLAGS) -fsanitize=address
OBJDIR	= build/
LIBFT	= libft/
SOURCES	= push_swap.c utils.c array_utils.c list_utils.c \
			print_utils.c
OBJECTS	= ${SOURCES:.c=.o}
ARGS	= 5 35 10# 20 40

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJECTS) -L$(LIBFT) -lft

$(OBJECTS): $(SOURCES)
	@$(CC) $(CFLAGS) -c $(SOURCES) -I $(LIBFT)includes/

valgrind: fclean
	@$(CC) $(DFLAGS) -c $(SOURCES) -I $(LIBFT)includes/
	@$(CC) -o $(NAME) $(DFLAGS) $(OBJECTS) -L$(LIBFT) -lft
	@valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(NAME) $(ARGS)

debug: fclean
	@$(CC) $(FFLAGS) -c $(SOURCES) -I $(LIBFT)includes/
	@$(CC) -o $(NAME) $(FFLAGS) $(OBJECTS) -L$(LIBFT) -lft
	./$(NAME) $(ARGS)


clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS)

.PHONY: clean fclean re run all debug valgrind
