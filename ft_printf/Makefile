CC=gcc
CFLAGS =
AR=ar
ARFLAGS=crs
NAME = libftprintf.a
SRCS= srcs/test.c \
	srcs/ft_printf.c \
	srcs/check_opt.c \
	srcs/ft_lib0.c \
	srcs/ft_lib1.c \
	srcs/ft_lib2.c \
	srcs/ft_lib3.c \
	srcs/hex_print.c \
	srcs/int_print.c \
	srcs/str_print.c
SRCS_BONUS= srcs/*.c
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
	@$(CC) $(CFLAGS) $^ -o tess
	@./tess

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

bonus:
	@make WITH_BONUS=1 all

clean:
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	@rm tess

re: fclean all
