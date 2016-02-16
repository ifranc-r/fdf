# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 11:11:02 by ifranc-r          #+#    #+#              #
#    Updated: 2016/02/16 16:41:58 by aramanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = includes/minilibx_macos/

LIB = -L ./libft/ -lft -./includes/minilibx_macos/ -lmlx -framework OpenGL\
	  -framework AppKit

SRC = ./srcs/main.c \
	./srcs/ft_get_map.c \
	./srcs/main.c

FlAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/
	@gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	@make clean -C libft/
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
	@make re -C libft/
