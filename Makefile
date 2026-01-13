# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 17:14:43 by yasmine.aichi     #+#    #+#              #
#    Updated: 2026/01/13 18:50:50 by yasmine.aichi    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFLAGS := -Wall -Wextra -Werror
CC := cc
SRC :=list.c \





OBJ := $(SRC:.c=.o)
#Target
NAME := libftprintf.a
HEADER := list.h \
		  bool.h \
		  stack_operations.h \

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $^


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


.PHONY: all clean fclean re
