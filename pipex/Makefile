CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex  # Zmieniamy na plik wykonywalny, nie biblioteka .a
RM = rm -rf
AR = ar rcs
FILES = pipex.c pipex_utils.c  # Upewnij się, że tu masz plik z funkcją main, czyli pipex.c
OBJS = $(FILES:.c=.o)  # Pliki obiektowe

LIBFT_PATH = libft
LIBFTNAME = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)  # Kompilujemy bibliotekę libft
	cp $(LIBFTNAME) .  # Kopiujemy libft.a do głównego katalogu
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) -o $(NAME)  # Kompilujemy program wykonywalny
	@echo "Program $(NAME) został pomyślnie utworzony!"

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