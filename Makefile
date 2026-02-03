# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 09:12:00 by yasmine.aichi     #+#    #+#              #
#    Updated: 2026/02/03 19:13:41 by yasmine.aichi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
NAME_TEST = test_push_swap

# Directories
OBJ_DIR = obj
SRC_DIR = .

# Source files for push_swap
SRCS = stack_init.c \
       stack_ops.c \
       stack_helpers.c \
       operations_swap.c \
       operations_rotate.c \
       operations_list.c
#a ajouter plus tard le parsing et le disorder

# Test files
TEST_SRCS = test_main.c

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I.

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

# Default target
all: $(NAME)

# Build push_swap (will need main.c later)
$(NAME): $(OBJS)
	@echo "$(YELLOW)Building $(NAME)...$(NC)"
	@echo "$(RED)Note: main.c not yet implemented, use 'make test' instead$(NC)"

# Build test executable
test: $(NAME_TEST)

$(NAME_TEST): $(OBJS) $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) -o $(NAME_TEST)
	@echo "$(GREEN)✓ $(NAME_TEST) compiled successfully!$(NC)"
	@echo "$(GREEN)Run with: ./$(NAME_TEST)$(NC)"

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(NC)"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Object files cleaned$(NC)"

# Clean everything
fclean: clean
	@rm -f $(NAME) $(NAME_TEST)
	@echo "$(GREEN)✓ Executables removed$(NC)"

# Rebuild everything
re: fclean all

# Run tests
run_test: test
	@echo "$(YELLOW)Running tests...$(NC)"
	@./$(NAME_TEST)

debug: CFLAGS += -g3 -DDEBUG
debug: re test
	@echo "$(YELLOW)Debug mode enabled$(NC)"

# Valgrind check
valgrind: test
	@echo "$(YELLOW)Running valgrind...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_TEST)

# Norminette check
norm:
	@echo "$(YELLOW)Checking norminette...$(NC)"
	@norminette *.c *.h || true

# Help
help:
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  make          - Build push_swap (requires main.c)"
	@echo "  make test     - Build test suite"
	@echo "  make run_test - Build and run tests"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make valgrind - Run tests with valgrind"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove all generated files"
	@echo "  make re       - Rebuild everything"
	@echo "  make norm     - Check norminette compliance"

.PHONY: all clean fclean re test run_test debug valgrind norm help
