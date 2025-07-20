CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LR = -lreadline

NAME = minishell

SRCS = main.c ft_free.c ft_isspace.c ft_lst.c ft_malloc.c ft_token_creat.c split.c token.c ft_memset.c ft_putstr_fd.c ft_putchar_fd.c ft_strcmp.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) $(LR) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY: clean fclean  all re
