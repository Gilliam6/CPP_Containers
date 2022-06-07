CFLAGS = -g -O0 -fsanitize=address -std=c++98 -Wall -Wextra -Werror
CPP = c++

NAME = ft_containers
STD = stdTest
FT = ftTest

TEST_BOOL1 = -D STATUS=1
TEST_BOOL0 = -D STATUS=0

SOURCE_LIST = vector.cpp
SRC_DIR = tests/
SOURCE = OBJ = $(addprefix $(SRC_DIR), $(SOURCE_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.cpp, %.o, $(SOURCE_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

OBJ_DIR_STD = objects_std/
OBJ_LIST = $(patsubst %.cpp, %.o, $(SOURCE_LIST))
OBJ_STD = $(addprefix $(OBJ_DIR_STD), $(OBJ_LIST))

OBJ_DIR_FT = objects_ft/
OBJ_LIST = $(patsubst %.cpp, %.o, $(SOURCE_LIST))
OBJ_FT = $(addprefix $(OBJ_DIR_FT), $(OBJ_LIST))

INCLUDE = -Ivector/ -Iutils/ -Iiter/
HEADER = vector/vector.hpp iter/*.hpp utils/utils.hpp
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
		@$(CPP) $(CFLAGS) $(TEST_BOOL0) -c $(INCLUDE) $< -o $@
		@echo "$(GREEN)$@ created$(RESET)"
#TEST FIELD

test: $(STD) $(FT)
		@./$(FT) > ft
		@./$(STD) > std
		@echo "=-=-=-=-= DIFF =-=-=-=-="
		@diff std ft
		@echo "=-=-=-= END DIFF =-=-=-="
		@#cat -e ft
		@rm -f std ft

$(STD): $(OBJ_DIR_STD) $(OBJ_STD)
		@$(CPP) $(CFLAGS) $(INCLUDE) $(OBJ_STD) -o $(STD)
		@echo "$stdTest:$(GREEN)created$(RESET)"

$(FT):	$(OBJ_DIR_FT) $(OBJ_FT)
		@$(CPP) $(CFLAGS) $(INCLUDE) $(OBJ_FT) -o $(FT)
		@echo "$ftTest:$(GREEN)created$(RESET)"

$(OBJ_DIR_FT):
		@mkdir -p $(OBJ_DIR_FT)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR_FT) was created$(RESET)"

$(OBJ_DIR_FT)%.o: $(SRC_DIR)%.cpp $(HEADER)
		@$(CPP) $(CFLAGS) $(TEST_BOOL0) -c $(INCLUDE) $< -o $@
		@echo "$(GREEN)$@ created$(RESET)"

$(OBJ_DIR_STD):
		@mkdir -p $(OBJ_DIR_STD)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR_STD) was created$(RESET)"

$(OBJ_DIR_STD)%.o: $(SRC_DIR)%.cpp $(HEADER)
		@$(CPP) $(CFLAGS) $(TEST_BOOL1) -c $(INCLUDE) $< -o $@
		@echo "$(GREEN)$@ created$(RESET)"

#END
clean:
		@echo "$(OBJ_DIR):$(GREEN) is cleaned$(RESET)"
		@rm -rf $(OBJ_DIR) $(OBJ_DIR_FT) $(OBJ_DIR_STD) $(STD) $(FT) ft std
fclean: clean
		@echo "$(NAME):$(GREEN) is cleaned$(RESET)"
		@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re test