# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 23:23:28 by minskim2          #+#    #+#              #
#    Updated: 2021/07/21 23:23:37 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = pipex
SRCS= \
	srcs/pipex.c \

SRCS_BONUS= \

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

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

bonus:
	@make WITH_BONUS=1 all

clean:
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
