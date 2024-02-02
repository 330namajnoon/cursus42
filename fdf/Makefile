NAME = libft.a
SRC = draw.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a \



SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = ar rcs

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(LIB) $@ $^

comp: 
	clang -D BUFFER_SIZE=100 -Wall -Wextra -Werror $(SRC) -lbsd -lmlx -lXext -lX11 -lm

bonus: $(OBJB) $(OBJ)
	$(LIB) $(NAME) $(OBJB) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all