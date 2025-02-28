MAKEFLAGS += --silent

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
	@echo "Done"

# Rule to create the executable
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "Done"

# Build libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)
	@echo "Done"

# Clean rule
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	@echo "Done"

# Fclean rule
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	@echo "Done"

# Rebuild everything
re: fclean all
	@echo "Done"

.PHONY: all clean fclean re $(LIBFT_A)