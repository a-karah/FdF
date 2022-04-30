CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = fdf
INCLUDES = -Iincludes
LIBFT_DIR = libft

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
MLX_DIR = minilibx_macos
MLX_FLAGS = -framework OpenGL -framework AppKit
else
MLX_DIR = minilibx-linux
MLX_FLAGS = -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

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

debug: CFLAGS += -fsanitize=address -g
debug: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) -sC $(MLX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

dre: debug all

.PHONY: all, debug, clean, fclean, re, dre
