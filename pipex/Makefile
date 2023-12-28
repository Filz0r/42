NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR)/includes -I$(INC_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
SRC_FILES = pipex.c utils.c commands.c debug.c cleanup.c
SRC_MAIN = main.c
BONUS_FILES = main_bonus.c utils_bonus.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

ifeq ($(MAKECMDGOALS), bonus)
	SRC_FILES += $(BONUS_FILES)
else
	SRC_FILES += $(SRC_MAIN)
endif

all: $(LIBFT) $(NAME)

bonus: CFLAGS += -g3 #-fsanitize=address
bonus: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LDFLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clion: CFLAGS += -g3 #-fsanitize=address
clion: all

valgrind: bonus
	@valgrind --log-file=valgrind.log --track-fds=yes -s --leak-check=full \
		--show-leak-kinds=all --trace-children=yes \
		--track-origins=yes ./$(NAME) infile $(CMDS) outfile

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clion bonus