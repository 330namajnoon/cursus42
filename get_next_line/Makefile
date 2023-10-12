
NAME = get_next_line

CC = gcc

SRC = main.c get_next_line.c get_next_line_utils.c 

CFLAGS = -Werror -Wall -Wextra

OBJ = $(SRC:.c=.o)

all = $(NAME)

%.c : %.o 
	$(CC) $(CFLAGS) -c $<

comp: $(OBJ)
	$(CC) -fsanitize=address -g -D BUFFER_SIZE=1 $(SRC)