CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_strjoin \
		ft_atoi \
		ft_memmove \
		ft_strnstr \
		ft_itoa \
		ft_strtrim \
		ft_striteri \
		ft_split \

NAME = libft.a
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean 
#reSRCS = $(addsuffix .c, $(FILES))
#OBJS = $(SRCS:.c=.o)

#all: $(NAME)

#$(NAME): $(OBJS)
#	$(AR) $(NAME) $(OBJS)
#	@echo "Library $(NAME) created successfully!"
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@
	
#clean:
#	$(RM) $(OBJS)

#fclean: clean
#	$(RM) $(NAME)

#re: fclean all

#.PHONY: all clean fclean re



