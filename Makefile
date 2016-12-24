# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 06:04:58 by mploux            #+#    #+#              #
#    Updated: 2016/12/24 18:19:32 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = gcc
FILES = main.c\
		rt_sdl.c\
		error.c\
		scene.c\
		inputs/input.c\
		inputs/keyboard.c\
		inputs/mouse.c\
		maths/vec2.c\
		maths/vec3.c\
		maths/vec3_1.c\
		maths/vec4.c\
		maths/transform.c\
		maths/projection.c\
		maths/mat4.c\
		maths/maths.c\
		graphics/renderer.c\
		graphics/display.c\
		graphics/color.c\
		graphics/bitmap_sdl.c\
		graphics/screen.c\
		graphics/line.c\
		graphics/ray.c\
		graphics/hit.c\
		graphics/camera.c\
		graphics/zbuffer.c\
		objects/object.c\
		objects/plane.c\
		objects/cylindre.c\
		objects/sphere.c

REPS = 	maths\
		inputs\
		graphics\
		objects

BIN = bin/
DIRS = $(addprefix $(BIN),$(REPS))
SRC = $(addprefix src/,$(FILES))
OBJ = $(addprefix $(BIN),$(FILES:.c=.o))

INCLUDES = -I includes/ -I libmlx-x11/ -I libft/
LIBS = -L libmlx-x11/ -L libft/

CFLAGS = -lmlx -lXext -lX11 -lft -lm -lSDL2
FLAGS = -g -Wall -Wextra -O2 -march=native -Ofast

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN) $(OBJ)
	@make -C libft/
	@make -C libmlx-x11/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIBS) $(CFLAGS)

$(BIN):
	@mkdir $(BIN)
	@mkdir -p $(DIRS)

bin/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(BIN)

fclean: clean
	rm -rf $(NAME)

re: fclean all
