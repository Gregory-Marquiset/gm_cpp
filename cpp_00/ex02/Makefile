SRCS = srcs/Account.cpp
INCLUDES = -Iincludes
NAME = $(notdir $(CURDIR))
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD -MP
RM = rm -rf
MK = mkdir -p

YELLOW = \033[1;33m
GREEN = \033[1;32m
CYAN = \033[1;36m
RED = \033[1;31m
RESET = \033[0m

OBJ_DIR = obj/
DEP_DIR = dep/
OBJ = $(SRCS:.cpp=.o)
OBJ_PREF = $(addprefix $(OBJ_DIR), $(OBJ))

DEPENDENCIES = $(OBJ_PREF:.o=.d)

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@echo "$(YELLOW)Compiling $(RESET)$(CYAN)$<$(RESET)..."
	@$(MK) $(dir $@) $(DEP_DIR)$(dir $<)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD -MF $(DEP_DIR)$*.d

$(NAME): $(OBJ_PREF)
	@echo "$(GREEN)Linking $(RESET)$(CYAN)$(NAME)$(RESET)..."
	$(CC) $(CFLAGS) $(OBJ_PREF) -o $(NAME)

clean:
	@echo "$(RED)Cleaning object files and dependencies...$(RESET)"
	$(RM) $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@echo "$(RED)Removing executable $(CYAN)$(NAME)$(RESET)..."
	$(RM) $(NAME)

re: fclean all

-include $(DEPENDENCIES)

.PHONY: all clean fclean re
