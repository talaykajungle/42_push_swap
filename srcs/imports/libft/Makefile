MAKEFLAGS += --silent
libft.a: $(OBJ)
#.SILENT: $(OBJS) $(NAME) $(LIBFT_A)

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_itoa.c ft_strmapi.c ft_striteri.c\
		ft_substr.c ft_strtrim.c ft_split.c ft_atoi.c ft_strjoin.c  \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c\
		./ft_printf/ft_printf.c ./ft_printf/ft_printf_utils.c ./ft_printf/ft_pointer.c ./ft_printf/ft_puthex.c

OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)
	@echo "Done"

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS) >/dev/null 2>&1
	@echo "Done"

so: $(OBJS) $(OBJS_BONUS)
	@$(CC) -nostartfiles -fPIC $(CFLAGS) -shared -o $(NAME).so $(OBJS) $(OBJS_BONUS)
	@echo "Done"

clean:
	$(RM) $(OBJS)
	@echo "clean"

fclean: clean
	$(RM) $(NAME) $(NAME).so
	@echo "fclean"

re: fclean $(NAME)
	@echo "Done"

.PHONY: all clean fclean re bonus so