#Compile Options
NAME = fractol
CC = cc
FLAGS =  -Wall -Wextra -Werror
MLXFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lm
# Directories
MLX = mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
SRC = sources/main.c sources/draw.c sources/error_check.c sources/fractals.c sources/utils.c sources/math.c
# Commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
# Defs
COLOR	= $(shell tput setaf 106)
D 		= $(shell tput sgr0)

all: checker $(NAME)

%.o : %.c
	@echo -n "$(COLOR)█$(D)"
	$(CC) $(FLAGS) -c $*.c -o $*.o

$(NAME) : start $(OBJ) newline $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(FLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)

$(LIBFT):
	@echo -n "[Compiling LIBFT]:"
	make -C includes/libft

$(PRINTF):
	@echo -n "[Compiling PRINTF]:"
	make -C includes/ft_printf

$(MLX):
	make -C mlx

start:
		@echo -n "[Compiling FRACT-OL]:"

checker:
	@if [ -d "mlx" ]; then echo "[MLX FOLDER FOUND]"; else make download; fi

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

mlx_clean:
	rm -rf mlx

clean:
	$(RM) $(OBJ)
	make -C includes/ft_printf clean
	make -C includes/libft clean

fclean: clean
	echo "Program deleted: $(COLOR)√$(D)"
	$(RM) $(NAME)
	echo "FT_PRINTF objects cleaned: $(COLOR)√$(D)"
	make -C includes/ft_printf fclean
	echo "LIBFT objects cleaned: $(COLOR)√$(D)"
	make -C includes/libft fclean

re: fclean all

newline:
	@echo "\n"

.SILENT:
