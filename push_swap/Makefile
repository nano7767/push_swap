# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svikornv <svikornv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 10:51:41 by svikornv          #+#    #+#              #
#    Updated: 2023/07/16 12:12:37 by svikornv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

#Commands
RM = rm -rf
AR = ar rc

#Directories
SRC_DIR = srcs
OBJ_DIR = objs
LIBFT_DIR = libft
INCLUDE_DIR = includes

#Sources and objects
SRCS = main.c \
	moves_a.c \
	moves_b.c \
	operations.c \
	push_swap.c \
	small_sort.c \
	radix_sort.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#Library and name tings
NAME = push_swap
LIBFT = libft/libft.a
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

#Build
all: $(LIBFT_DIR) $(NAME)

#Rule to build library
$(LIBFT):
	make -C $(LIBFT_DIR)

#Compile obj
$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

#Target library build rule
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

#clean
clean:
	$(RM) $(OBJ_DIR)
	mkdir $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

#fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	make fclean -C $(LIBFT_DIR)

#clean and rebuild the target library
re: fclean all

#Phony targets
.PHONY: all clean fclean