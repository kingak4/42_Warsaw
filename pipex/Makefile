CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex.a
RM = rm -rf
AR = ar rcs
FILES =  pipex \
	     pipex_utils \
		
LIBFT_PATH = libft
LIBFTNAME = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	cp $(LIBFTNAME) .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

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