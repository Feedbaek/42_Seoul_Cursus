CC=gcc
CFLAGS = -Werror -Wextra -Wall
AR=ar
ARFLAGS=crs
NAME = libftprintf.a
SRCS= \
	srcs/ft_printf.c \
	srcs/check_opt.c \
	srcs/ft_lib0.c \
	srcs/ft_lib1.c \
	srcs/ft_lib2.c \
	srcs/ft_lib3.c \
	srcs/hex_print.c \
	srcs/int_print.c \
	srcs/str_print.c
SRCS_BONUS= \
	srcs/ft_printf.c \
	srcs/check_opt.c \
	srcs/ft_lib0.c \
	srcs/ft_lib1.c \
	srcs/ft_lib2.c \
	srcs/ft_lib3.c \
	srcs/hex_print.c \
	srcs/int_print.c \
	srcs/str_print.c
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
