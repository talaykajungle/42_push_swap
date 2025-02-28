# Name of the executable
NAME = push_swap

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source directories
SRCDIR = srcs
LIBFT = ./srcs/imports/libft

# Source files (list all .c files)
SRCS = $(SRCDIR)/main/main.c \
       $(SRCDIR)/rules/ft_push_ops.c \
       $(SRCDIR)/rules/ft_rev_rot_ops.c \
       $(SRCDIR)/rules/ft_rot_ops.c \
       $(SRCDIR)/rules/ft_swap_ops.c \
       $(SRCDIR)/sorts/sort_checker.c \
       $(SRCDIR)/sorts/sort.c

OBJS = $(SRCS:.c=.o)

# Library files
LIBFT_A = $(LIBFT)/libft.a

# Default target
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Build libft
$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

# Clean rule
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean

# Fclean rule
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re $(LIBFT_A)