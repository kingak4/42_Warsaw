CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC =
		libft/libft.a\

NAME = pipex 
$(NAME) :
		make all -C libft
		gcc $(CFLAGS) $(SRC) -o $(NAME)
all : $(NAME)
fclean = clean
		$(RM) $(NAME)
		make clean -C libft
clean :
		$(RM) $(NAME)
		make clean -C libft
re : fclean all
