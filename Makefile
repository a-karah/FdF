CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	MLX_DIR = minilibx_linux
	MLX_FLAGS = -L/usr/bin/lib/ -lXext -lX11 -lm
endif

ifeq ($(UNAME), Darwin)
	MLX_DIR = $(HOME)/minilibx_macos
	MLX_FLAGS = -framework OpenGL -framework AppKit
	MLX_INCLUDE = -I$(HOME)/minilibx_macos
endif

NAME = fdf
INCLUDES = -Iincludes
LIBFT_DIR = libft

SRCS = main.c \
		draw.c \
		error.c \
		utils.c \
		colors.c \
		checks.c \
		fdf_utils.c \
		parse_map.c \
		draw_utils.c \
		handle_key.c \
		color_utils.c \
		handle_window.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(MLX_INCLUDE)

clean:
	@$(MAKE) -sC $(MLX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
