#Compile Options
NAME = fractol
CC = cc
CFLAGS =  -Wall -Wextra -Werror
MLXFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lm
# Directories
MLX = mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
SRC = sources/command.c sources/main.c sources/draw.c sources/error_check.c sources/fractals.c sources/utils.c sources/utils2.c sources/math.c sources/zoom.c
# Commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
# Defs
GREEN=\e[38;5;118m
END= $<\e[0m

all: checker $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS)

$(LIBFT):
	@make --silent -C includes/libft

$(PRINTF):
	@make --silent -C includes/ft_printf

$(MLX):
	make -C mlx

checker:
	@if [ -d "mlx" ]; then echo "$(GREEN)[MLX FOLDER FOUND]$(END)"; else make download; fi

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

mlx_clean:
	rm -rf mlx

clean:
	$(RM) $(OBJ)
	@make --silent -C includes/ft_printf clean
	@make --silent -C includes/libft clean

fclean: clean
	$(RM) $(NAME)
	@make --silent -C includes/ft_printf fclean
	@make --silent -C includes/libft fclean

re: fclean all

