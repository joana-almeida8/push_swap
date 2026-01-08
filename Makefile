# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/15 09:07:40 by jreis-de          #+#    #+#              #
#    Updated: 2026/01/08 13:09:24 by jreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
		libft/printf/ft_printf_utils.c libft/printf/ft_printf_utilz.c \
		libft/printf/ft_printf.c libft/ft_calloc.c libft/ft_substr.c \
		libft/ft_bzero.c libft/ft_strlen.c \
		parsing/counting.c parsing/parse.c parsing/utils.c \
		operations/push.c operations/reverse.c \
		operations/rotate.c operations/swap.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -g
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re