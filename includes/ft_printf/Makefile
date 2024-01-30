NAME = libftprintf.a
CC= cc -g
FLAGS= -Wall -Wextra -Werror
SRC= ft_flags.c ft_printf.c ft_printhexa.c ft_printint.c ft_printpointer.c ft_putchar.c ft_putnbr.c ft_putstr.c
RM = rm -rf
OBJS=$(SRC:.c=.o)
COLOR	= $(shell tput setaf 106)
D 		= $(shell tput sgr0)

all: $(NAME) newline

%.o : %.c
	echo -n "$(COLOR)████$(D)";
	$(CC) $(FLAGS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

newline:
	echo -n "$(COLOR)██$(D)";
	echo "\n"

re: fclean all
