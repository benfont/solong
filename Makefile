# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:52:06 by aitlopez          #+#    #+#              #
#    Updated: 2023/03/14 19:27:51 by aitlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

SRC = so_long.c check_errors.c ft_split.c  get_next_line.c map.c utils.c utils1.c check_barrier.c check_rectangle.c check_characters.c upload_images.c  print_map.c ft_print_characters.c ft_movements.c ft_check_items.c free_map.c ft_putchar.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = so_long.h

RM = rm -f

%.o : %.c
	make -C mlx
	$(CC) -c $(FLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)


clean :
	$(RM) $(OBJ)
	make clean -C mlx

fclean : clean
	$(RM) $(NAME)
	@echo "$(NAME) cleaned!$(NC)"

re : fclean all

run : ./so_long  map1.ber

norm:
	@norminette

.PHONY = all clean fclean re norm run
