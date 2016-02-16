# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 11:11:02 by ifranc-r          #+#    #+#              #
#    Updated: 2016/02/16 15:00:05 by aramanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_test

HEAD = includes/minilibx_macos/

LIB = -L ./libft/ -lft -./includes/minilibx_macos/ -lmlx -framework OpenGL\
	  -framework AppKit

SRC = ./srcs/main.c \
	  			./srcs/get_next_line.c\
				./scr/ft_get_map.c\
				./srcs/main.c

FlAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIB)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(HEAD) -I ./libft/includes/ -I ./includes/

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) ./libft/libft.a

re: fclean all
