# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 17:15:47 by dmukaliy          #+#    #+#              #
#    Updated: 2020/01/21 10:12:06 by dmukaliy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
SRC = ./src/*.c
LIB_SRC = ./libft/*.c
FLAGS = -Wall -Wextra -Werror -c
HEADER = ./includes
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(LIB_SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
