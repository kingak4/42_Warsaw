CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
RM = rm -rf
AR = ar rcs

FILES = start.c hooks.c map_check.c make_game.c clear_game.c moves.c else.c map_check_1.c final_check.c
OBJS = $(FILES:.c=.o) 

LIBFT_PATH = libft
LIBFTNAME = $(LIBFT_PATH)/libft.a

MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
INCLUDES = -Imlx -I/usr/include -I$(LIBFT_PATH)/includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C mlx
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFTNAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C mlx
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make clean -C mlx
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re