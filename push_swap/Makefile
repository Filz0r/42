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
SOURCES_MAIN	= push_swap.c
SRC_UTILS		=  	$(SOURCES_UTILS)list_utils.c \
					$(SOURCES_UTILS)print_utils.c $(SOURCES_UTILS)utils.c \
					$(SOURCES_UTILS)sort_utils.c $(SOURCES_UTILS)math_utils.c \
					$(SOURCES_UTILS)utils2.c $(SOURCES_UTILS)sort_big_utils.c \
					$(SOURCES_UTILS)sort_big_utils2.c
SRC_MOVES		= $(SOURCES_MOVES)swap.c  $(SOURCES_MOVES)push.c \
					$(SOURCES_MOVES)rotate.c $(SOURCES_MOVES)rev_rotate.c

SRC				= $(SRC_UTILS) $(SOURCES_MAIN) $(SOURCES_SORT) $(SRC_MOVES)
OBJ				= $(subst $(SOURCES_UTILS),$(OBJDIR), $(SRC_UTILS:.c=.o)) \
 					$(subst $(SOURCES_MOVES),$(OBJDIR), $(SRC_MOVES:.c=.o)) \
					$(OBJDIR)$(SOURCES_MAIN:.c=.o)
ARGS	= 6 52 10 3 2 7 5 4 21 1

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling push_swap"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft
	@echo "Done!"

$(LIBFT):
	@git clone git@github.com:Filz0r/libft.git
	@make -C $(LIBFT)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR) $(LIBFT)
	@echo "Compiling source files into object files"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(LIBFT)includes/
	@mv *.o $(OBJDIR)
	@echo "Done!"

valgrind: fclean $(OBJDIR)
	@$(CC) $(DFLAGS) -c $(SRC) -I $(LIBFT)includes/
	mv *.o $(OBJDIR)
	@$(CC) -o $(NAME) $(DFLAGS) $(OBJ) -L$(LIBFT) -lft
	@valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(NAME) $(ARGS)

debug: fclean $(OBJDIR)
	@$(CC) $(FFLAGS) -c $(SRC) -I $(LIBFT)includes/
	@mv *.o $(OBJDIR)
	@$(CC) -o $(NAME) $(FFLAGS) $(OBJ) -L$(LIBFT) -lft

clion: fclean $(OBJDIR)
	@$(CC) $(DFLAGS) -c $(SRC) -I $(LIBFT)includes/
	@mv *.o $(OBJDIR)
	@$(CC) -o $(NAME) $(DFLAGS) $(OBJ) -L$(LIBFT) -lft

libft: $(LIBFT)

clean:
	@rm -rf $(OBJDIR)

lclean:
	@rm -rf $(LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS)

.PHONY: clean fclean re run all debug valgrind lclean clion
