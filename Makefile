# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 06:04:58 by mploux            #+#    #+#              #
#    Updated: 2017/05/10 23:13:36 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = gcc

GREEN = \033[0;49;32m
GREEN_B = \033[1;49;32m
YELLOW = \033[0;49;93m
NO_COLOR = \033[m
WIDTH = $(eval WIDTH=$(shell tput cols))

DEPS_DIR = deps
BIN_DIR = bin
SRCS_DIR = srcs
INCLUDES_DIR = includes

SDL_DIR = $(DEPS_DIR)/SDL2-2.0.5
SDL_LIB_DIR = $(SDL_DIR)/build/.libs
SDL_LIB = $(SDL_LIB_DIR)/libSDL2.a
SDL_INCLUDES = $(SDL_DIR)/include

LIBFT_DIR = $(DEPS_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)

SYSTEM = $(shell uname -s)

FILES =\
error.c\
graphics/bitmap.c\
graphics/camera.c\
graphics/color.c\
graphics/display.c\
graphics/line.c\
graphics/renderer.c\
graphics/screen.c\
hit.c\
light.c\
main.c\
maths/mat4.c\
maths/maths.c\
maths/projection.c\
maths/transform.c\
maths/vec2.c\
maths/vec3.c\
maths/vec3_1.c\
maths/vec4.c\
objects/cone.c\
objects/cylindre.c\
objects/object.c\
objects/plane.c\
objects/sphere.c\
scenes/scene.c\
scenes/scene_renderer.c\
scenes/parser/scene_parser.c\
scenes/parser/parse_objects.c\
scenes/parser/parse_position.c\
scenes/parser/parse_rotation.c\
scenes/parser/parse_scale.c\
scenes/parser/parse_transform.c\
scenes/parser/parse_color.c\
quadratics/intersect.c\
quadratics/normal.c\
quadratics/rotate_x.c\
quadratics/rotate_y.c\
quadratics/rotate_z.c\
quadratics/scale.c\
quadratics/translate.c\
ray.c\
rt.c

SRCS = $(addprefix $(SRCS_DIR)/,$(FILES))
OBJS = $(addprefix $(BIN_DIR)/,$(FILES:.c=.o))

INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_INCLUDES)/ -I $(SDL_INCLUDES)/
LIBS = -L $(LIBFT_DIR) -L $(SDL_LIB_DIR)

ifeq (SYSTEM, Darwin)
	SDL_FLAGS = -lSDL2 -framework Cocoa -framework CoreAudio -framework AudioToolbox -framework ForceFeedback -framework CoreVideo -framework Carbon -framework IOKit -liconv
else
	SDL_FLAGS = -lSDL2 -lXext -lX11 -lft -lm -ldl
endif

FLAGS = -Wall -Wextra -O2 -march=native -Ofast -pedantic

.PHONY: all test clean clean-libs fclean re

$(NAME): $(SDL_LIB) $(LIBFT_LIB) $(BIN_DIR) $(OBJS)
	@printf "\r$(YELLOW)Building RTv1...$(NO_COLOR)";
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) -lft $(SDL_FLAGS)
	@printf "\r$(GREEN)Building RTv1: DONE !$(NO_COLOR)\n\n";
	@printf "\r$(GREEN)Building done: $(GREEN_B)$(NAME)$(NO_COLOR)\n";

all: $(NAME)

$(SDL_LIB):
	@printf "\r$(YELLOW)Building SDL2...$(NO_COLOR)                ";
	@$(shell tar -xzf $(SDL_DIR).tar.gz -C $(DEPS_DIR))
	@printf "\r$(YELLOW)Building SDL2: Configuring...$(NO_COLOR)   ";
	@cd $(SDL_DIR) && ./configure > /dev/null
	@printf "\r$(YELLOW)Building SDL2: Making...$(NO_COLOR)        ";
	@make -C $(SDL_DIR) > /dev/null 2> /dev/null
	@printf "\r$(YELLOW)Building SDL2: Removing dylib...$(NO_COLOR)";
	@rm -rf $(SDL_LIB_DIR)/libSDL2-2.0.0.dylib
	@printf "\r$(GREEN)Building SDL2: DONE !$(NO_COLOR)            \n";

$(LIBFT_LIB):
	@printf "\r$(YELLOW)Building libft...$(NO_COLOR)      ";
	@make -C $(LIBFT_DIR) > /dev/null
	@printf "\r$(GREEN)Building libft: DONE !$(NO_COLOR)\n";

$(BIN_DIR):
	@mkdir -p $(dir $(OBJS))

$(BIN_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(FLAGS) -MMD -o $@ -c $< $(INCLUDES)

test: all
	@./$(NAME)

clean:
	@rm -rf $(BIN_DIR)

clean-libs: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -rf $(SDL_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
