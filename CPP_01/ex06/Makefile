NAME := harlFilter
CXX := c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 
BUILD_DIR := obj
SRC_FULL := main.cpp \
			Harl.cpp

OBJ := $(addprefix $(BUILD_DIR)/, $(SRC_FULL:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) successfully built."

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< successfully."

clean:
	@rm -fr $(BUILD_DIR)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Project cleaning is finished."

re: fclean all

.PHONY: all clean fclean re 


