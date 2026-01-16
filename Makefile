# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 09:07:40 by jreis-de          #+#    #+#              #
#    Updated: 2026/01/16 12:08:10 by jreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = srcs/libft/
PARSE = srcs/parse/
OPS = srcs/ops/
ALG = srcs/algorithm/

SRCS = include/main.c \
		$(LIBFT)printf/ft_printf_utils.c $(LIBFT)printf/ft_printf_utilz.c \
		$(LIBFT)printf/ft_printf.c $(LIBFT)ft_substr.c $(LIBFT)ft_strlen.c \
		$(PARSE)counting.c $(PARSE)parse.c $(PARSE)utils.c \
		$(OPS)push.c $(OPS)reverse.c $(OPS)rotate.c $(OPS)swap.c \
		$(ALG)operate_stack.c $(ALG)small_swaps.c $(ALG)big_swaps1.c \
		$(ALG)big_swaps2.c \

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -g
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

vpath %.c $(dir $(SRCS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@echo "Objects and $(OBJ_DIR)/ directory removed."

fclean: clean
	$(RM) $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re