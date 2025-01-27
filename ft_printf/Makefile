CC = cc
CFLAGS =  -Wall -Wextra -Werror
AR = ar rcs;
RM = rm -f;
FILES = ft_printf \
		ft_putstr \
		ft_putnbr \
		
NAME = libftprintf.a
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
