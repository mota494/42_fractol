NAME = fractol
# :3
CC = cc
FLAGS =  -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext -lm
MLX = mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
RM = rm -rf
# >:3
SRC = sources/main.c
OBJ = $(SRC:.c=.o)
# <:3
all: $(NAME)

$(NAME) : checker $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(FLAGS) $(MLXFLAGS) $(SRC) -o $(NAME) $(LIBFT) $(PRINTF) $(MLX)

$(LIBFT):
	make -C includes/libft

$(PRINTF):
	make -C includes/ft_printf

$(MLX):
	make -C mlx

checker:
	if [ -d "mlx" ]; then echo "mlx folder found"; else make download; fi

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

clean:
	$(RM) $(OBJ)
	make -C includes/ft_printf clean
	make -C includes/libft clean

fclean: clean
	$(RM) $(NAME) mlx
	make -C includes/ft_printf fclean
	make -C includes/libft fclean

re: fclean download all
