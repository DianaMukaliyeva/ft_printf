# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diana <diana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 17:15:47 by dmukaliy          #+#    #+#              #
#    Updated: 2020/02/02 22:43:44 by diana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
FLAGS = -Wall -Wextra -Werror -c
HEADER = ./includes

SRC_DIR = ./src/
SRC = ft_printf.c parse_flags.c print_arg.c print_char.c print_double.c\
		print_effects.c print_int.c print_memory.c print_number_with_flags.c\
		print_oux.c print_str.c print_unsigned_number.c printf_putchar.c\
		str_with_precision.c
SRCS=$(addprefix $(SRC_DIR), $(SRC))

LIB_SRC_DIR = ./libft/
LIB_SRC = ft_atoi.c ft_itoa.c ft_memdel.c ft_memset.c ft_strcat.c ft_strchr.c\
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c\
		ft_strncpy.c ft_strnew.c ft_strrev.c
LIB_SRCS=$(addprefix $(LIB_SRC_DIR), $(LIB_SRC))

OBJ = $(SRC:%.c=%.o) $(LIB_SRC:%.c=%.o)

RESET = \033[0m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BOLD_BLUE = \033[1;34m

all: $(NAME)

$(NAME):
	@echo "$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is compiling...$(GREEN)>>$(RESET)"
	@gcc $(FLAGS) $(SRCS) $(LIB_SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is ready to use$(GREEN)>>$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "   $(GREEN)<<$(RESET)$(YELLOW)all o.files are deleted$(GREEN)>>$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "    $(GREEN)<<$(RESET)$(YELLOW)$(NAME) deleted$(GREEN)>>$(RESET)"

re: fclean all

.PHONY: all clean fclean re
