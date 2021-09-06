# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/09/06 16:06:41 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
SRCS =	srcs/push_swap.c \
	srcs/push_swap_v2.c \
	srcs/sort_start.c \
	srcs/tools0.c \
	srcs/tools1.c \
	srcs/ft_split.c \
	srcs/init.c \
	srcs/cnt_instruction.c \
	srcs/run_instruction.c \
	srcs/sort_section.c \
	srcs/section.c \
	srcs/find_pivot.c \
	srcs/find.c \
	srcs/action_swap.c \
	srcs/action_push.c \
	srcs/action_rotate.c \
	srcs/action_reverse_rotate.c

SRCS_BONUS = srcs/checker.c \
	srcs/sort_start.c \
	srcs/push_swap_v2.c \
	srcs/tools0.c \
	srcs/tools1.c \
	srcs/ft_split.c \
	srcs/init.c \
	srcs/cnt_instruction.c \
	srcs/run_instruction.c \
	srcs/sort_section.c \
	srcs/section.c \
	srcs/find_pivot.c \
	srcs/find.c \
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
	NAME = checker_test
	OBJS = $(OBJECTS_BONUS)
else
	NAME = push_swap
	OBJS = $(OBJECTS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -g $(CFLAGS) -c $^ -o $@ -I $(HEADER)

bonus:
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	rm -rf push_swap checker_test $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
