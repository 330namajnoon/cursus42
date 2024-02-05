NAME = libft.a
SRC = main.c \
 create_scene.c \
 create_eages.c \
 read_map.c \
 draw.c \
 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a \




CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = ar rcs

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(LIB) $@ $^

comp: 
	clang -D BUFFER_SIZE=100 -Wall -Wextra -Werror $(SRC) -lbsd -lmlx -lXext -lX11 -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all