# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 12:09:16 by ghenriqu          #+#    #+#              #
#    Updated: 2025/05/30 12:48:18 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = push_swap

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror

# basic and additional files:
SRC = 	0-main.c \
		1-input_check.c \
		1-split.c \
		2-filling.c \
		2-indexation.c \
		3-push.c \
		3-reverse_rotate.c \
		3-rotate.c \
		3-swap.c \
		4-sort.c \
		4-sort_tiny.c \
		5-cost.c \
		5-do_move.c \
		5-position.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

# standard rule:
all: $(NAME)

# compile and create the lib:
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Let's go! Push_swap built."

# compile .o:
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

# clean files:
clean:
	@$(RM) $(OBJ)
	@echo "Object files gone!"

# clean everything, .o and libft.a:
fclean: clean
	@$(RM) $(NAME)
	@echo "Binary gone!"

# recompile all:
re: fclean all

.PHONY: all re clean fclean
