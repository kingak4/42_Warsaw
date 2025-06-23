CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
RM = rm -rf
AR = ar rcs

FILES = checkers.c make_tab.c clear_code.c operations.c operations_2.c code_alg.c sort45.c algo_help.c helper_alg.c final_alg.c
OBJS = $(FILES:.c=.o) 

LIBFT_PATH = libft
LIBFTNAME = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTNAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re