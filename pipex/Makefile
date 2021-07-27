# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 23:23:28 by minskim2          #+#    #+#              #
#    Updated: 2021/07/27 17:22:55 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = pipex
SRCS= \
	srcs/pipex.c \
	srcs/ft_split.c \
	srcs/ft_strjoin.c \
	srcs/path_finder.c \
	srcs/redirect.c \
	srcs/utils.c \

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
	@$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADER)

bonus:
	@make WITH_BONUS=1 all

clean:
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	@rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
