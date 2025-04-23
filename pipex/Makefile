CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex 
RM = rm -rf
AR = ar rcs
FILES = pipex.c pipex_utils.c  
OBJS = $(FILES:.c=.o) 

LIBFT_PATH = libft
LIBFTNAME = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) -o $(NAME) 
	@echo "Program $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re