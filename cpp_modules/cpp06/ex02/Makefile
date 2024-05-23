NAME = identify
CXX = c++
CXXFLAGS =  -std=c++98 -Wall -Wextra -Werror -g3 #-fsanitize=address
SRC = 	main.cpp Base.cpp Identify.cpp
BUILD_DIR = build
INCLUDES = -I.
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(NAME): $(OBJ)
	@echo "Compiling $@..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES)
	@echo "Done!"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@mkdir -p $(@D)
	@echo "Compiling $@..."
	@$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned $(NAME) and object files"

re: fclean all

.PHONY: all clean fclean re