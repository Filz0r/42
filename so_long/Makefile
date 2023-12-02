# Project name
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-O2
INCLUDES = -I$(LIBFT_DIR)/inc -I$(MLX_DIR) -I/usr/include
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
LIBFT_DIR = libft
MLX_DIR = mlx
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a
SRC_FILES = so_long.c utils/utils.c utils/errors.c utils/map_parser.c \
		utils/map_utils.c utils/map_utils2.c engine/game_init.c  \
		engine/game_cleanup.c engine/images.c engine/loader.c engine/map.c \
	 	engine/window.c engine/cleanup.c engine/game_run.c engine/utils.c \
	 	engine/render.c engine/movement.c engine/frame.c engine/events.c \
	 	engine/debug.c engine/light_map.c engine/points.c engine/info_panel.c \
	 	engine/queue.c
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
	@make -s -C $(LIBFT_DIR) debug

$(MLX):
	@make -s -C $(MLX_DIR)

clion: CFLAGS += -g3# -fsanitize=address
clion: all

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re clion
