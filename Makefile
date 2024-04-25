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

CFLAGS = -Wall -Wextra -Werror -g3

INC = include/pipex.h

SRCS = main.c \
	   utils.c \
	   utils2.c \
       pipex.c \


BSRCS = ./bonus/main_bonus.c \
		./bonus/here_doc_bonus.c \
 		./bonus/utils_bonus.c \
	  	./bonus/utils2_bonus.c \
		./bonus/pipex_bonus.c \

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

LIBFT = ./libft/libft.a

NAME = pipex

B_NAME = pipex_bonus

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C libft
	@echo "$(GREEN)libft.a created$(RESET)"

$(NAME) : $(OBJS) $(INC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)pipex created$(RESET)"

bonus : $(B_NAME)

$(B_NAME) : $(BOBJS) $(INC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(B_NAME) $(BOBJS) $(LIBFT)
	@echo "$(GREEN)pipex_bonus created$(RESET)"

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	rm -f $(BOBJS)
	make -C libft clean
	@echo "$(YELLOW)objects removed$(RESET)"

fclean : clean
	rm -f $(NAME)
	rm -f $(B_NAME)
	make -C libft fclean
	@echo "$(RED)$(NAME) removed$(RESET)"

re : fclean all

.PHONY : all bonus clean fclean re
