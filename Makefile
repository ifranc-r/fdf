# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/20 18:39:07 by ifranc-r          #+#    #+#              #
#    Updated: 2016/03/04 18:18:39 by aramanan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = includes/minilibx_macos/

LIB = -L ./libft/ -lft -L ./includes/minilibx_macos/ -lmlx -framework OpenGL\
	  -framework AppKit

SRC = ./srcs/main.c \
	srcs/key_hook/mov.c \
	srcs/coord/coord.c \
	srcs/coord/fill_coord.c \
	srcs/parser/parse.c \
	srcs/error/error.c \
	srcs/map/map.c \
	srcs/map/content.c \
	srcs/draw/draw_tab.c \
	srcs/draw/bresenham.c \
	srcs/draw/ft_init_bres.c \
	srcs/draw/ft_octant.c \
	srcs/draw/ft_arc.c \
	srcs/mlx/mlx.c

ifdef FLAG
	ifeq ($(FLAG), no)
		FLAGS =
	endif
else
	FLAGS = -Wall -Wextra -Werror
endif

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/ -g
	@gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
	@make re -C libft/
