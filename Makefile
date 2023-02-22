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
SRC = check_errors.c get_next_line.c utils.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = so_long.h

RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) - c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclear : clean
	$(RM) $(NAME)
	@echo "$(NAME) cleaned!$(NC)"

re : fclean all

.PHONY = all clean fclean re
