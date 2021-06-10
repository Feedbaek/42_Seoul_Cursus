CC=gcc
CFLAGS =-Wall -Wextra -Werror
AR=ar
ARFLAGS=crs
NAME = libftprintf.a
SRCS= SRCS/ft_printf.c
SRCS_BONUS= SRCS/ft_printf.c
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)
ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(OBJECTS_BONUS)
else
	OBJS = $(OBJECTS)
endif

HEADER = include

.PHONY: all clean fclean bonus re

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

bonus:
	@make WITH_BONUS=1 all

clean:
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
