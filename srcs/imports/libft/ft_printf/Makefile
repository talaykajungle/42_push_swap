MAKEFLAGS += --silent
.SILENT: $(OBJS) $(NAME) $(LIBFT_A)

# Variables
SRCS =  ft_printf.c ft_printf_utils.c ft_pointer.c ft_puthex.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIBFTDIR)

# Default target
all: $(NAME)
	@echo "Done"

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	@echo "Done"

# Rule to compile object files
%.o: %.c
	@CC $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	@echo "clean"

# fclean rule
fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	@echo "fclean"

# Rebuild rule
re: fclean $(NAME)
	@echo "Done"

.PHONY: all clean fclean re