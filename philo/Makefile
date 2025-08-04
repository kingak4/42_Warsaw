CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
RM = rm -rf
AR = ar rcs

FILES = checkres.c
OBJS = $(FILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	make -C 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	make clean -C 
	$(RM) $(OBJS)

fclean: clean
	make fclean -C 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re