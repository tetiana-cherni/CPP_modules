NAME := megaphone

CXX := c++
CXXFLAGC := -Wall -Wextra -Werror -std=c++17 
BUILD_DIR := obj
SRC := megaphone.cpp
OBJ := $(addprefix $(BUILD_DIR)/,$(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGC) $(OBJ) -o $(NAME)
	@echo "$(NAME) successfully built."

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGC) -c $< -o $@
	@echo "Object files created."

clean:
	@rm -fr $(BUILD_DIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Project cleaning is finished."

re: fclean all

.PHONY: all clean fclean re

