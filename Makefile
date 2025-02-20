# Colors
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
RED = \033[0;91m

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
# CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f

# Directories and files
LIBFTDIR = lib/ultimate_libft/
LIBFT_LIB = $(LIBFTDIR)/ultimate_libft.a
HEADER = include/minitalk.h

# Source files
SRCS_CLIENT = src/client.c
SRCS_SERVER = src/server.c

# Object files
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Executable names
NAME_CLIENT = client
NAME_SERVER = server

# Build everything
all: make_libft $(NAME_SERVER) $(NAME_CLIENT)

# Compile .c to .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Build server
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT_LIB) Makefile $(HEADER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_LIB) -o $(NAME_SERVER)
	@echo "$(GREEN)Server compiled!$(DEF_COLOR)"

# Build client
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT_LIB) Makefile $(HEADER)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_LIB) -o $(NAME_CLIENT)
	@echo "$(GREEN)Client compiled!$(DEF_COLOR)"

# Build libft
make_libft:
	make -C $(LIBFTDIR)

# Clean objects
clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	@cd $(LIBFTDIR) && $(MAKE) clean
	@echo "$(RED)Cleaned object files$(DEF_COLOR)"

# Clean all files
fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

# Rebuild project
re: fclean all

.PHONY: all clean fclean re make_libft