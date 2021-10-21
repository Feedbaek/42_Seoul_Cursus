# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 19:26:51 by minskim2          #+#    #+#              #
#    Updated: 2021/10/21 18:45:43 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
SRCS =	srcs/philo.c \
	srcs/tools0.c \
	srcs/init.c \
	srcs/pthread.c \
	srcs/mornitor.c

SRCS_BONUS =

HEADER = include

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	NAME = philo_bonus
	OBJS = $(OBJECTS_BONUS)
else
	NAME = philo
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
	rm -rf philo philo_bonus $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all
