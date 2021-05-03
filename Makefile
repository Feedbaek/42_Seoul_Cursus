CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = libft.a
all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJS)
	ar rc $@ $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
