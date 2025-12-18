# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:05:10 by jbarreir          #+#    #+#              #
#    Updated: 2025/12/18 18:16:55 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = srcs/main.c \
	  srcs/ft_atoi.c \
	  srcs/ft_putnbr.c \
	  srcs/my_math.c \
	  srcs/ft_putstr.c
INCLUDES = -I includes
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
