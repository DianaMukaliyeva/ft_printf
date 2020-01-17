# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diana <diana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 17:15:47 by dmukaliy          #+#    #+#              #
#    Updated: 2020/01/17 13:32:35 by diana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
SRC = ./src/*.c
FLAGS = -Wall -Wextra -Werror -c
HEADER = ./includes
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
