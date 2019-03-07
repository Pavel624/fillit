NAME	= fillit
CFLAGS	= -Wall -Werror -Wextra -I. -g
FILES	= main.c read.c
LIB	= ./libft/libft.a
				
OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(OBJ): $(FILES)
	gcc $(CFLAGS) -c $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all