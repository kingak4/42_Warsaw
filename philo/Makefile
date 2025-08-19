CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo
RM = rm -rf

FILES = checkers.c ft_atol.c main.c print.c utils.c one_philo.c init_philo.c routine.c monitor.c d_check.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re