NAME = fractol
# :3
CC = cc
FLAGS =  -Wall -Wextra -Werror
MLX = mlx
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
RM = rm -rf
# >:3
SRC = sources/main.c
OBJ = $(SRC:.c=.o)
# <:3
all: $(NAME)

$(NAME) : download $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C includes/libft

$(PRINTF):
	make -C includes/ft_printf

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

fclean:
	$(RM) $(NAME) $(OBJ) $(MLX)
	make -C includes/ft_printf fclean
	make -C includes/libft fclean
