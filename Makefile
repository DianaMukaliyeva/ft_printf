# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 17:15:47 by dmukaliy          #+#    #+#              #
#    Updated: 2020/01/09 11:06:43 by dmukaliy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
SRC = *.c
FLAGS = -Wall -Wextra -Werror -c
HEADER = ./
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
