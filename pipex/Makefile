NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR)/inc
LDFLAGS = -L$(LIBFT_DIR) -lft
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_FILES = pipex.c utils.c commands.c debug.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)

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

valgrind: clion
	@valgrind --log-file=valgrind.log --track-fds=yes -s --leak-check=full \
		--show-leak-kinds=all --trace-children=yes \
		--track-origins=yes ./$(NAME) infile $(CMDS) outfile

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clion