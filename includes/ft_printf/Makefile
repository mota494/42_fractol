NAME = libftprintf.a
CC= cc -g
CFLAGS= -Wall -Wextra -Werror
SRC= ft_flags.c ft_printf.c ft_printhexa.c ft_printint.c ft_printpointer.c ft_putchar.c ft_putnbr.c ft_putstr.c
RM = rm -rf
OBJS=$(SRC:.c=.o)
GREEN=\e[38;5;118m
END= $<\e[0m

all: start $(NAME)

start:
	echo "$(GREEN)[COMPILING FT_PRINTF WITH $(CFLAGS)]$(END)"

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all
