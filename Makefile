# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 09:12:00 by yasmine.aic       #+#    #+#              #
#    Updated: 2026/02/11 22:45:00 by mberraho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = push_swap
NAME_OP_TEST    = test_operations
NAME_PARSER_TEST = test_parser

OBJ_DIR = obj


STACK_SRCS = stack_init.c \
             stack_ops.c \
             stack_helpers.c


OPS_SRCS = operations_swap.c \
           operations_rotate.c \
           operations_list.c

# [TODO] Ajoute ici les fichiers du parser au fur et a mesure
PARSER_SRCS = initialize_parser.c \
              reactions_WhenInNumber.c \
              utils_parsing.c
#             reactions_WhenInStart1.c \
#             reactions_WhenInStart2.c \
#             ... etc.

# --- Module Disorder : calcul du desordre pour la strategie adaptive ---
#TODO
# DISORDER_SRCS = disorder.c


MAIN_PUSH_SWAP   = main.c
MAIN_OP_TEST     = test_main.c
MAIN_PARSER_TEST = parser.c

# Sources pour chaque executable
SRCS_PUSH_SWAP   = $(STACK_SRCS) $(OPS_SRCS) $(PARSER_SRCS) $(MAIN_PUSH_SWAP)
SRCS_OP_TEST     = $(STACK_SRCS) $(OPS_SRCS) $(MAIN_OP_TEST)
SRCS_PARSER_TEST = $(STACK_SRCS) $(OPS_SRCS) $(PARSER_SRCS) $(MAIN_PARSER_TEST)

OBJS_PUSH_SWAP   = $(SRCS_PUSH_SWAP:%.c=$(OBJ_DIR)/%.o)
OBJS_OP_TEST     = $(SRCS_OP_TEST:%.c=$(OBJ_DIR)/%.o)
OBJS_PARSER_TEST = $(SRCS_PARSER_TEST:%.c=$(OBJ_DIR)/%.o)


CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
INCLUDES = -I.

GREEN  = \033[0;32m
YELLOW = \033[0;33m
RED    = \033[0;31m
NC     = \033[0m


# --- Target par defaut ---
all: $(NAME)

# --- Compilation de push_swap ---
# [TODO] Decommenter quand main.c de tout le programme existera
# $(NAME): $(OBJS_PUSH_SWAP)
# 	@$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) -o $(NAME)
# 	@echo "$(GREEN)✓ $(NAME) compile !$(NC)"
$(NAME):
	@echo "$(RED)main.c pas encore implemente. Utilise 'make test_ops'$(NC)"

# --- Compilation du test des operations ---
$(NAME_OP_TEST): $(OBJS_OP_TEST)
	@$(CC) $(CFLAGS) $(OBJS_OP_TEST) -o $(NAME_OP_TEST)
	@echo "$(GREEN)✓ $(NAME_OP_TEST) compile !$(NC)"

# --- Compilation du test du parser ---
#$(NAME_PARSER_TEST): $(OBJS_PARSER_TEST)
 #	@$(CC) $(CFLAGS) $(OBJS_PARSER_TEST) -o $(NAME_PARSER_TEST)
#	@echo "$(GREEN)✓ $(NAME_OP_TEST) compile !$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(NC)"

clean:
	@rm -rf $(OBJ_DIR) #[TODO] Add make ops dir
	@echo "$(GREEN)✓ Fichiers objets supprimes$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME_OP_TEST) 
	@echo "$(GREEN)✓ Executables supprimes$(NC)"

re: fclean all


# Compile et lance le test des operations
test_ops: $(NAME_OP_TEST)
	@echo "$(YELLOW)Lancement des tests operations...$(NC)"
	@./$(NAME_OP_TEST)

# Compile et lance le test du parser
#test_parser: $(NAME_PARSER_TEST)
 #	@echo "$(YELLOW)Lancement des tests parser...$(NC)"
# 	@./$(NAME_PARSER_TEST)

# Valgrind sur le test des operations
valgrind: $(NAME_OP_TEST)
	@echo "$(YELLOW)Valgrind en cours...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME_OP_TEST)

norm:
	@norminette *.c *.h || true

help:
	@echo "$(YELLOW)Targets disponibles :$(NC)"
	@echo "  make            - Build push_swap (quand main.c existera)"
	@echo "  make test_ops   - Compile et lance les tests operations"
	@echo "  make test_parser   - Compile et lance les tests du"
	@echo "  make valgrind   - Test operations avec valgrind"
	@echo "  make clean      - Supprime les .o"
	@echo "  make fclean     - Supprime tout (clean + executables)"
	@echo "  make re         - Recompile tout depuis zero"
	@echo "  make norm       - Verifie la norminette"

.PHONY: all clean fclean re test_ops test_parser valgrind norm help
