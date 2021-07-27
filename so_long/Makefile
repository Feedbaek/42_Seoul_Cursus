# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/07/28 01:46:13 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = so_long
minilibx = srcs/minilibx_opengl_20191021
SRCS = srcs/so_long.c \

SRCS_BONUS= \

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(OBJECTS_BONUS)
else
	OBJS = $(OBJECTS)
endif

HEADER = include

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L $(minilibx) -lmlx -framework OpenGL -framework AppKit $^ -o $@
%.o: %.c
	make -C $(minilibx)
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER) -I $(minilibx)

bonus:
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	make clean -C $(minilibx)

fclean:
	rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	make clean -C $(minilibx)

re: fclean all
	make re -C ${minilibx}
