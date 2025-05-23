MAKEFLAGS += --silent
.SILENT: $(OBJS) $(NAME) $(LIBFT_A)

# Name of the executable

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Source directories
SRCDIR = srcs
LIBFT = ./srcs/imports/libft

# Source files (list all .c files)
SRCS =	$(SRCDIR)/main/main.c \
		$(SRCDIR)/main/mainsupport.c\
		$(SRCDIR)/main/radix.c \
		$(SRCDIR)/main/arg_check.c \
		$(SRCDIR)/rules/ft_push_ops.c \
		$(SRCDIR)/rules/ft_rev_rot_ops.c \
		$(SRCDIR)/rules/ft_rot_ops.c \
		$(SRCDIR)/rules/ft_swap_ops.c \
		$(SRCDIR)/rules/list_rules1.c \
		$(SRCDIR)/rules/list_rules2.c \
		$(SRCDIR)/sorts/sort_checker.c \
		$(SRCDIR)/sorts/sort.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_A = $(LIBFT)/libft.a


# Default target
all: $(NAME)
	@echo "push_swap: nothing to be done for (all)"

# Rule to create the executable
$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "Push_swap made - Done"

# Explicit rule for .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)
	@echo "Libft - Done"

# Clean rule
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	# @echo "clean"

# Fclean rule
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	# @echo "fclean"

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

# Rebuild everything
re: fclean all
	# @echo "Done"

# .PHONY: all clean fclean re
