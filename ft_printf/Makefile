CC = cc
CFLAGS =  -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FILES = ft_printf \
		ft_putstr \
		ft_putnbr \
		ft_printx \
		ft_print_uperx \
		ft_print_pointer \
		ft_intlen \
		ft_putchar \

		
NAME = libftprintf.a
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(SRCS:.c=.o)

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
	$(RM) $(LIBFTNAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
