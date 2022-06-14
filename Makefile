# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 11:54:44 by hkhalil           #+#    #+#              #
#    Updated: 2022/05/20 11:57:12 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c check_for_errors.c get_next_line.c get_next_line_utils.c utils.c key_hook.c map_draw.c utils1.c

OBJ = $(SRC:.c=.o)

CFLAGS = -D BUFFER_SIZE=10 -Wall -Wextra -Werror -g -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
