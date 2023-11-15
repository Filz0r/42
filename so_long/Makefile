NAME 			= so_long
CC 				= cc
CFLAGS 			= #-Wall -Werror -Wextra
DFLAGS 			= $(CFLAGS) -g3
FFLAGS 			= $(DFLAGS) -fsanitize=address
OBJDIR 			= build/
LIBFT_DIR		= libft/
MLX				= mlx/
SRC_DIR 		= src/
SRC_UTILS		= $(SRC_DIR)utils/
SOURCES_MAIN	= $(SRC_DIR)so_long.c
SOURCES_UTILS	= $(SRC_UTILS)maps.c $(SRC_UTILS)errors.c
SRC				= $(SOURCES_MAIN) $(SOURCES_UTILS)
OBJ				= $(subst $(SRC_DIR),$(OBJDIR), $(SOURCES_MAIN:.c=.o)) \
				$(subst $(SRC_UTILS),$(OBJDIR), $(SOURCES_UTILS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
	@echo "Done!"

libft:
	@echo "Compiling $(LIBFT_DIR)"
	@echo "=========OUTPUT_START========="
	@make -s -C $(LIBFT_DIR)
	@echo "=========OUTPUT_END========="
	@echo "Done!"

mlx:
	@echo "Compiling $(MLX)"
	@echo "=========OUTPUT_START========="
	@make -s -C $(MLX)
	@echo "=========OUTPUT_END========="
	@echo "Done!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR) libft mlx
	@echo "Compiling Source files into Object Files"
	@$(CC) $(CFLAGS) -c $(SRC) -I$(LIBFT_DIR)includes/ -I$(MLX) -I/usr/include
	@mv *.o $(OBJDIR)
	@echo "Done!"

libclean:
	@echo "Cleaning libft"
	@make -s -C $(LIBFT_DIR) fclean
	@echo "Cleaning mlx"
	@make -s -C $(MLX) clean

clean:
	@rm -rf $(OBJDIR)

fclean: clean libclean
	@rm -rf $(NAME)

clion: fclean libft mlx $(OBJDIR)
	@$(CC) $(DFLAGS) -c $(SRC) -I $(LIBFT_DIR)includes/ -I$(MLX) -I/usr/include
	@mv *.o $(OBJDIR)
	@$(CC) -o $(NAME) $(DFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


re: fclean all

.PHONY: clean fclean all re clion mlx libft