# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 16:30:54 by jbarreir          #+#    #+#              #
#    Updated: 2025/12/14 12:36:04 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRC = srcs/ft_strlen.c \
	  srcs/ft_puterr.c \
	  srcs/main.c

OBJ = $(SRC:.c=.o)
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all
