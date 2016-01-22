#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 15:48:58 by mdriay            #+#    #+#              #
#    Updated: 2015/04/18 19:03:44 by mdriay           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select
SRC =	./src/main.c \
		./src/ft_list.c \
		./src/ft_command.c \
		./src/ft_size.c \
		./src/ft_signal.c \
		./src/ft_signal_helper.c \
		./src/ft_key_enter.c \
		./src/ft_putchar_auto.c \
		./src/ft_print_list.c

OBJ = $(SRC:.c=.o)

LIBFT = -L./libft -lft

FLAG = -Wall -Werror -Wextra

CC = gcc

%.o: %.c
	$(CC) -c -o $@ $< $(FLAG)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	$(CC) $(OBJ) $(FLAG) -ltermcap -o $(NAME) $(LIBFT)
	@echo compiled

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all