NAME = ScavTrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/ClapTrap.cpp \
	  $(SRC_DIR)/ScavTrap.cpp

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
