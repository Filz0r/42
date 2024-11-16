#NAME = gnl
NAME_BONUS = gnl_bonus
CC = cc
INCLUDE=include
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE)
OBJ_DIR = build
#SRC_DIR = src
BONUS_DIR = bonus
#SRC_FILES = get_next_line.c get_next_line_utils.c test.c
BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c test_bonus.c
#SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
#OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

#all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJ_DIR):
	@mkdir -rp $(OBJ_DIR)

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Done!"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

#$(NAME): $(OBJS)
#	@echo "Compiling $@"
#	@$(CC) $(CFLAGS) -o $@ $^
#	@echo "Done!"
#
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@mkdir -p $(@D)
#	@echo "Compiling $@"
#	@$(CC) $(CFLAGS) -o $@ -c $<
#

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
#	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

#re: fclean all

rb: fclean bonus

.PHONY: all clean fclean re bonus