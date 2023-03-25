CC = gcc

CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
