# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/09 20:37:52 by kkuvalis          #+#    #+#              #
#    Updated: 2019/03/31 17:03:24 by kkuvalis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC  = main.c addititonal.c read.c hitmebaby.c onemoretime.c

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

INC_LIB = libft

HEAD = libft/libft.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -I$(INC_LIB) -o $(NAME)
	
$(LIBFT):
	make -C libft/

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -I$(INC_LIB)

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
	make -C libft re
