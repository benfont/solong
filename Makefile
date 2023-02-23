# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:52:06 by aitlopez          #+#    #+#              #
#    Updated: 2023/02/22 10:58:10 by aitlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc
SRC = check_errors.c get_next_line.c utils.c utils1.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = so_long.h

RM = rm -f

%.o : %.c
	make -C
	$(CC) $(FLAGS) -I$< -o $@

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	@echo "$(NAME) cleaned!$(NC)"

re : fclean all
norm:
	@norminette

.PHONY = all clean fclean re norm
