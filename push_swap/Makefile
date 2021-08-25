# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/08/25 17:50:22 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap
SRCS =	srcs/push_swap.c \
	srcs/tools0.c \
	srcs/tools1.c \
	srcs/ft_split.c \
	srcs/init.c \
	srcs/action_swap.c \
	srcs/action_push.c \
	srcs/action_rotate.c \
	srcs/action_reverse_rotate.c
SRCS_BONUS=

HEADER = include

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(OBJECTS_BONUS)
else
	OBJS = $(OBJECTS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

bonus:
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
