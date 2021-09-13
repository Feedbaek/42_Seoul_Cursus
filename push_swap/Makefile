# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/09/14 01:23:33 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
SRCS =	srcs/push_swap.c \
	srcs/a_to_b.c \
	srcs/set_a_to_b.c \
	srcs/b_to_a.c \
	srcs/set_b_to_a.c \
	srcs/tools0.c \
	srcs/tools1.c \
	srcs/ft_split.c \
	srcs/init.c \
	srcs/find_pivot.c \
	srcs/action_swap.c \
	srcs/action_push.c \
	srcs/action_rotate.c \
	srcs/action_reverse_rotate.c

SRCS_BONUS = srcs/checker.c \
	srcs/a_to_b.c \
	srcs/set_a_to_b.c \
	srcs/b_to_a.c \
	srcs/set_b_to_a.c \
	srcs/tools0.c \
	srcs/tools1.c \
	srcs/ft_split.c \
	srcs/init.c \
	srcs/find_pivot.c \
	srcs/action_swap.c \
	srcs/action_push.c \
	srcs/action_rotate.c \
	srcs/action_reverse_rotate.c \
	srcs/gnl/get_next_line.c \
	srcs/gnl/get_next_line_utils.c \
	srcs/gnl/get_next_line_utils2.c

HEADER = include

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	NAME = checker
	OBJS = $(OBJECTS_BONUS)
else
	NAME = push_swap
	OBJS = $(OBJECTS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

bonus:
	make all
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	rm -rf push_swap checker $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
