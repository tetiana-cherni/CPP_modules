NAME := phonebook

CXX := c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 
BUILD_DIR := obj
INC_DIR := include
CXXFLAGS += -I $(INC_DIR)
SRC_DIR := src
SRC_MAIN := main.cpp

SRC := contact.cpp \
	phone_book.cpp

SRC_FULL = $(SRC_MAIN) $(SRC)

OBJ := $(addprefix $(BUILD_DIR)/,$(SRC_FULL:.cpp=.o))

#test
TEST_NAME = test_phonebook
TEST_DIR := tests
TEST_FLAGS := -I $(TEST_DIR) -pthread
TEST_SRC := $(addprefix $(SRC_DIR)/, $(SRC)) \
		$(TEST_DIR)/test_contact.cpp \

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

test:
	@echo "Test compilation starts.."
	@$(CXX) $(CXXFLAGS) $(TEST_FLAGS) $(TEST_SRC) -o $(TEST_DIR)/$(TEST_NAME)
	@echo "Run tests:"
	@./$(TEST_DIR)/$(TEST_NAME)

.PHONY: all clean fclean re test

