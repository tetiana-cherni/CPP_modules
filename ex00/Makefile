NAME := zombie

CXX := c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
BUILD_DIR := obj
INC_DIR := include
CXXFLAGS += -I $(INC_DIR)
SRC_MAIN := main.cpp
SRC_DIR := src

SRC := Zombie.cpp \
	newZombie.cpp \
	randomChump.cpp

SRC_FULL = $(SRC_MAIN) $(SRC)

OBJ := $(addprefix $(BUILD_DIR)/,$(SRC_FULL:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) successfully built."

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
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


