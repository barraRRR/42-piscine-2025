NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes

SRC = srcs/main.c \
	  srcs/ft_puterr.c

OBJ = $(SRC:.c=.o)
RM = rm -f

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
