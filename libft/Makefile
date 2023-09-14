NAME = myProgram

SRC = main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc



OBJ = $(SRC:.c=.o)

all = $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $<
	

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
