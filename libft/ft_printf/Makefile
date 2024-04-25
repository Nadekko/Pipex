DEF_COLOR = \033[0;39m
RED = \033[0;91m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_aff.c ft_printf_nbr.c ft_printf_utils.c ft_printf_unsign.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
