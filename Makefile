# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mploux <mploux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 06:04:58 by mploux            #+#    #+#              #
#    Updated: 2017/03/29 16:19:27 by mploux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = gcc

DEPS_DIR = deps
BIN_DIR = bin
SRCS_DIR = srcs
INCLUDES_DIR = includes

SDL_DIR = $(DEPS_DIR)/SDL2-2.0.5
SDL_LIB = $(SDL_DIR)/.libs/libSDL2.a
SDL_INCLUDES = $(SDL_DIR)/include

LIBFT_DIR = $(DEPS_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)

FILES =\
main.c

SRCS = $(addprefix $(SRCS_DIR)/,$(FILES))
OBJS = $(addprefix $(BIN_DIR)/,$(FILES:.c=.o))

INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_INCLUDES)/
LIBS = -L $(LIBFT_DIR)

CFLAGS = -lSDL2 -lXext -lX11 -lft -lm -ldl
FLAGS = -Wall -Wextra -O2 -march=native -Ofast -pedantic

.PHONY: all clean fclean re

$(NAME): $(SDL_LIB) $(LIBFT_LIB) $(BIN_DIR) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS) $(CFLAGS)

all: $(NAME)

$(SDL_LIB):
	$(shell tar -xzf $(SDL_DIR).tar.gz -C $(DEPS_DIR))
	cd $(SDL_DIR) && ./configure
	make -C $(SDL_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(BIN_DIR):
	@mkdir -p $(dir $(OBJS))

$(BIN_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(FLAGS) -MMD -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf $(BIN_DIR)

clean-libs: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -rf $(SDL_DIR)

fclean: clean-libs
	@rm -rf $(NAME)

re: fclean all
