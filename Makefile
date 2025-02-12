# Name
NAME = push_swap

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR = src
HEDDIR = header
LIBDIR = import
OBJDIR = obj

# Libraries
LIBFT = $(LIBDIR)/libft
FT_PRINTF = $(LIBDIR)/ft_printf

# Source & Object files

SRC = 

OBJ = $(SRC: .c=.o)

# Executable name
TARGET = push_swap

# Included Directories
INCLUDES = -I$(HEDDIR) -I$(LIBFT) -I$(FT_PRINTF)/$(HEDDIR)

# Included Libraries
LIBS = -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

# Default TARGET
all: $(TARGET)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build the target executable
$(TARGET): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
	$(make) -C $(LIBFTDIR) clean
	$(make) -C $(FT_PRINTF) clean

# fclean rule
fclean: clean
	rm -f $(TARGET)
	cd $(LIBFTDIR) && make fclean

# Rebuild rule
re: fclean all

.PHONY: all clean fclean re