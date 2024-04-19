NAME = Polymorphism4
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address
SRC = main.cpp IceMateria.cpp AMateria.cpp MateriaSource.cpp Character.cpp CureMateria.cpp
BUILD_DIR = build
INCLUDES = -Iinclude
SRCS = $(addprefix src/, $(SRC))
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(NAME): $(OBJ)
	@echo "Compiling $@..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES)
	@echo "Done!"

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
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