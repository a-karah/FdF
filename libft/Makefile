NAME = libft.a
INCL_FOLDER = includes
SRCS_NAMES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line.c \
		ft_printf.c print_nbr.c print_text.c print_nbr_utils.c \
		ft_max.c ft_abs.c ft_swap.c ft_deg_rad.c
SRCS_FOLDER = srcs/
SRCS = $(addprefix $(SRCS_FOLDER), $(SRCS_NAMES))
OBJS_NAMES = $(SRCS_NAMES:.c=.o)
OBJS_FOLDER = objs/
OBJS = $(addprefix $(OBJS_FOLDER), $(OBJS_NAMES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

all: $(NAME)

$(OBJS_FOLDER):
	@mkdir -p $(OBJS_FOLDER)

$(NAME): $(OBJS_FOLDER) $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL_FOLDER)

test: all
	$(CC) $(CFLAGS) ./test/main.c -L. -lft
	@mv ./a.out ./test
	@./test/a.out

clean:
	$(RM) $(OBJS_FOLDER)

fclean: clean
	$(RM) $(NAME)
	$(RM) ./test/a.out

re: fclean all

.PHONY: all, clean, fclean, re, test
