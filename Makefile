# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 20:14:26 by dkajiwar          #+#    #+#              #
#    Updated: 2024/11/28 18:58:05 by dkajiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEAD = push_swap.h
SRCS = main.c node_initialization.c bit_operations.c utils.c node_operations_1.c node_operations_2.c node_operations_3.c sort.c handle_errors.c simple_sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	$(CC) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) -c utils.c -o utils.o
	$(CC) $(CFLAGS) -c node_operations_1.c -o node_operations_1.o
	$(CC) $(CFLAGS) -c node_operations_2.c -o node_operations_2.o
	$(CC) $(CFLAGS) -c node_operations_3.c -o node_operations_3.o
	$(CC) $(CFLAGS) -c bit_operations.c -o bit_operations.o
	$(CC) $(CFLAGS) -c sort.c -o sort.o
	$(CC) $(CFLAGS) -c handle_errors.c -o handle_errors.o
	$(CC) $(CFLAGS) -c node_initialization.c -o node_initialization.o
	$(CC) $(CFLAGS) -c simple_sort.c -o simple_sort.o


clean:
	make -C ./ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./ft_printf fclean
	rm -f $(NAME)

re: fclean all