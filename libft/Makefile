MAKEFLAGS += -s
NAME = libft.a
SRC = main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \


SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = ar rcs

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

MAKEFLAGS += -s

all : $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $<


$(NAME): $(OBJ)
	$(LIB) $@ $^

comp: $(OBJ) $(OBJB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(OBJB)

san: $(OBJ) $(OBJB)
	$(CC) -fsanitize=address -g  $(SRC) $(SRCB) 

bonus: $(OBJB) $(OBJ)
	$(LIB) $(NAME) $(OBJB) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean

