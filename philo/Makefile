NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread
INCLUDES = -I$(INC_DIR)
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
SRC_FILES = main.c errors.c utils.c init.c threads.c routine.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LDFLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

valgrind: re
	@truncate -s 0 valgrind.log
	@valgrind --log-file=valgrind.log --tool=helgrind \
		--history-level=approx ./$(NAME) 5 810 200 200

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re valgrind