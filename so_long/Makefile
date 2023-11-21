# Project name
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = $(CFLAGS) -g3 #-fsanitize=address
INCLUDES = -I$(LIBFT_DIR)/inc -I$(MLX_DIR) -I/usr/include
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
LIBFT_DIR = libft
MLX_DIR = mlx
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a
SRC_FILES = map_parser.c so_long.c utils/errors.c utils/map_utils.c utils/utils.c engine/utils.c \
			engine/game_init.c utils/map_utils2.c
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
	@$(CC) $(DFLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(MLX):
	@make -s -C $(MLX_DIR)

clion: $(CFLAGS) = $(DFLAGS)
clion: all


clean:
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
