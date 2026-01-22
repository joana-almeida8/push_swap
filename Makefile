# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 09:07:40 by jreis-de          #+#    #+#              #
#    Updated: 2026/01/22 15:22:52 by jreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT = srcs/libft/
PARSE = srcs/parse/
OPS = srcs/ops/
ALG = srcs/algorithm/
BONUS = bonus/
OBJ_DIR = objs/
OBJ_DIR_BONUS = bonus/objs/

SRCS = srcs/main.c \
		$(LIBFT)printf/ft_printf_utils.c \
		$(LIBFT)printf/ft_printf_utilz.c \
		$(LIBFT)printf/ft_printf.c \
		$(LIBFT)ft_substr.c \
		$(LIBFT)ft_strlen.c \
		$(PARSE)counting.c \
		$(PARSE)parse.c \
		$(PARSE)utils.c \
		$(OPS)swap.c \
		$(OPS)push.c \
		$(OPS)rotate.c \
		$(OPS)reverse.c \
		$(ALG)operate_stack.c \
		$(ALG)calcs.c \
		$(ALG)small_swaps.c \
		$(ALG)chunk_to_b.c \
		$(ALG)turc_to_a.c

SRCS_BONUS = $(BONUS_DIR)srcs/checker.c \
				$(BONUS_DIR)srcs/checker_utils.c \
				$(BONUS_DIR)get_next_line/get_next_line.c \
				$(BONUS_DIR)get_next_line/get_next_line_utils.c \
				$(OPS)swap.c \
				$(OPS)push.c \
				$(OPS)rotate.c \
				$(OPS)reverse.c \
				$(PARSE)parse.c \
				$(PARSE)utils.c \
				$(PARSE)counting.c \
				$(ALG)calcs.c \
				$(ALG)turc_to_a.c \
				$(ALG)chunk_to_b.c \
				$(ALG)small_swaps.c \
				$(ALG)operate_stack.c \
				$(LIBFT)ft_substr.c \
				$(LIBFT)ft_strlen.c \
				$(LIBFT)printf/ft_printf.c \
				$(LIBFT)printf/ft_printf_utils.c \
				$(LIBFT)printf/ft_printf_utilz.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(notdir $(SRCS_BONUS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: srcs/libft/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: srcs/libft/printf/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: srcs/algorithm/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: srcs/parse/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: srcs/ops/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	
$(OBJ_DIR_BONUS)%.o: bonus/srcs/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: srcs/libft/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR_BONUS)%.o: srcs/libft/printf/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: srcs/algorithm/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: srcs/parse/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: srcs/ops/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: srcs/algorithm/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: bonus/get_next_line/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@echo "Objects removed."

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "Removed $(NAME) $(NAME_BONUS)"

re: fclean all

.PHONY: all bonus clean fclean re