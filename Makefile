# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 09:12:00 by yasmine.aic       #+#    #+#              #
#    Updated: 2026/02/09 20:30:16 by mberraho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
NAME_OP_TEST = test_operations
NAME_PARSER_TEST = test_parser

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
TEST_SRCS_PARSER = test_parser.c

# Object files
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:%.c=$(OBJ_DIR)/%.o)
TEST_PARSER = $(TEST_SRCS_PARSER:%.c=$(OBJ_DIR)/%.o)

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

# Build test of operations executable
test_operations: $(NAME_OP_TEST)

$(NAME_OP_TEST): $(OBJS) $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) -o $(NAME_OP_TEST)
	@echo "$(GREEN)✓ $(NAME_OP_TEST) compiled successfully!$(NC)"
	@echo "$(GREEN)Run with: ./$(NAME_OP_TEST)$(NC)"

# Build test of parser executable
test_parser: $(NAME_PARSER_TEST)

$(NAME_PARSER_TEST): $(OBJS) $(TEST_PARSER)
	@$(CC) $(CFLAGS) $(OBJS) $(TEST_PARSER) -o $(NAME_OP_TEST)
	@echo "$(GREEN)✓ $(NAME_PARSER_TEST) compiled successfully!$(NC)"
	@echo "$(GREEN)Run with: ./$(NAME_PARSER_TEST)$(NC)"

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
	@rm -f $(NAME) $(NAME_OP_TEST)
	@echo "$(GREEN)✓ Executables removed$(NC)"

# Rebuild everything
re: fclean all

# Run tests
run_test_operations: test
	@echo "$(YELLOW)Running tests of operations ...$(NC)"
	@./$(NAME_OP_TEST)

# Run tests
run_test_parser: test
	@echo "$(YELLOW)Running tests of operations ...$(NC)"
	@./$(NAME_OP_TEST)

debug: CFLAGS += -g3 -DDEBUG
debug: re test
	@echo "$(YELLOW)Debug mode enabled$(NC)"

# Valgrind check
valgrind: test
	@echo "$(YELLOW)Running valgrind...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_OP_TEST)

# Norminette check
norm:
	@echo "$(YELLOW)Checking norminette...$(NC)"
	@norminette *.c *.h || true

# Help toucu
help:
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  make          - Build push_swap (requires main.c)"
	@echo "  make test     - Build test suite"
	@echo "  make run_test_operations - Build and run tests on operations"
	@echo "  make run_test_operations - Build and run tests on parsing"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make valgrind - Run tests with valgrind"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove all generated files"
	@echo "  make re       - Rebuild everything"
	@echo "  make norm     - Check norminette compliance"

.PHONY: all clean fclean re test run_test debug valgrind norm help
