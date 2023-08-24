NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
DFLAGS			= $(CFLAGS) -g3
FFLAGS			= $(DFLAGS) -fsanitize=address
OBJDIR			= build/
LIBFT			= libft/
SOURCES_UTILS	= utils/
SOURCES_MOVES	= moves/
TESTS_SRC		= tests/
SOURCES_SORT	= sort_three.c sort_five.c
SOURCES_MAIN	= push_swap.c
SRC_UTILS		= $(SOURCES_UTILS)array_utils.c $(SOURCES_UTILS)list_utils.c \
					$(SOURCES_UTILS)print_utils.c $(SOURCES_UTILS)utils.c \
					$(SOURCES_UTILS)sort_utils.c
SRC_MOVES		= $(SOURCES_MOVES)swap.c  $(SOURCES_MOVES)push.c \
					$(SOURCES_MOVES)rotate.c $(SOURCES_MOVES)rev_rotate.c

SRC				= $(SRC_UTILS) $(SOURCES_MAIN) $(SOURCES_SORT) $(SRC_MOVES)
OBJ				= $(subst $(SOURCES_UTILS),$(OBJDIR), $(SRC_UTILS:.c=.o)) \
 					$(subst $(SOURCES_MOVES),$(OBJDIR), $(SRC_MOVES:.c=.o)) \
					$(OBJDIR)$(SOURCES_MAIN:.c=.o) \
					$(addprefix $(OBJDIR), $(SOURCES_SORT:.c=.o)) #adds the build/ prefix to all vars
ARGS	= 5 35 10# 20 40

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft

$(LIBFT):
	git clone git@github.com:Filz0r/libft.git

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ): $(SRC) $(OBJDIR) $(LIBFT)
	$(CC) $(CFLAGS) -c $(SRC) -I $(LIBFT)includes/
	mv *.o $(OBJDIR)

valgrind: fclean
	@$(CC) $(DFLAGS) -c $(SOURCES) -I $(LIBFT)includes/
	@$(CC) -o $(NAME) $(DFLAGS) $(OBJECTS) -L$(LIBFT) -lft
	@valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(NAME) $(ARGS)

debug: fclean $(OBJDIR)
	@$(CC) $(FFLAGS) -c $(SRC) -I $(LIBFT)includes/
	@mv *.o $(OBJDIR)
	@$(CC) -o $(NAME) $(FFLAGS) $(OBJ) -L$(LIBFT) -lft
	./$(NAME) $(ARGS)

$(TESTS_SRC):
	@mkdir $(TESTS_SRC)

clean:
	@rm -rf $(OBJDIR)

lclean:
	@rm -rf $(LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS)

.PHONY: clean fclean re run all debug valgrind
