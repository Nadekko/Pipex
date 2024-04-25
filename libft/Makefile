DEF_COLOR = \033[0;39m
RED = \033[0;91m
YELLOW = \033[0;93m

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strjoin.c ft_strmapi.c \
	ft_strlcat.c ft_strncmp.c ft_strcmp.c ft_atoi.c ft_isalpha.c ft_split.c \
	ft_strchr.c  ft_strlcpy.c ft_strtrim.c ft_substr.c ft_itoa.c ft_atol.c \
	ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
	ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_striteri.c \
	ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

FT_PRINTF =  ./ft_printf/libftprintf.a

NAME = libft.a

all: $(NAME)


$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(FT_PRINTF):
	make -C ft_printf

bonus: $(BOBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -c $(BSRCS)
	ar rc $(NAME) $(BOBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
