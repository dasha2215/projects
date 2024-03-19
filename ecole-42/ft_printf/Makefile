# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsiroten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 12:22:21 by dsiroten          #+#    #+#              #
#    Updated: 2024/02/22 13:10:36 by dsiroten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_put_unsigned_int.c ft_putnbr.c ft_putaddress.c \
ft_putstr.c ft_printf.c ft_putchar.c  ft_puthex.c 
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT =	libft

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $?

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
