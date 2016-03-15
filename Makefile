# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:41:24 by adespond          #+#    #+#              #
#    Updated: 2016/03/15 13:32:18 by adespond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= src/main.c \
		  src/init.c \
		  src/key.c \
		  src/expose.c \
		  src/mouse.c \
		  src/text.c \
		  src/loop.c \
		  src/move.c \
		  src/error.c \
		  src/color.c \
		  src/utils.c \
		  src/mandelbrot.c \
		  src/julia.c \
		  src/burningship.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all
