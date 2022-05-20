CFLAGS = -std=c++98 -Wall -Wextra -Werror
CPP = c++

NAME = vector

SOURCE_LIST = vector.cpp
SRC_DIR = src/
SOURCE = OBJ = $(addprefix $(SRC_DIR), $(SOURCE_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.cpp, %.o, $(SOURCE_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

INCLUDE = -Isrc/vector.hpp
HEADER = src/vector.hpp
RM = rm -f

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m


all: $(NAME)

$(NAME):  $(OBJ_DIR) $(OBJ)
		@$(CPP) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
		@echo "\n$(NAME):$(GREEN)created =)!\n$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
		@$(CPP) $(CFLAGS) -c $(INCLUDE) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

clean:
		@echo "$(OBJ_DIR):$(GREEN) is cleaned$(RESET)"
		@rm -rf $(OBJ_DIR)
fclean: clean
		@echo "$(NAME):$(GREEN) is cleaned$(RESET)"
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re