# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/08/17 20:53:43 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = so_long
minilibx_path = srcs/minilibx_mms_20210621
minilibx = libmlx.dylib
SRCS = srcs/so_long.c \
	srcs/config.c \
	srcs/key_input.c \
	srcs/gnl/get_next_line_utils.c \
	srcs/gnl/get_next_line.c
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

all: make_mini $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L . -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER) -I $(minilibx_path)

make_mini:
	make -C $(minilibx_path)
	mv ./$(minilibx_path)/$(minilibx) .

bonus:
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	make clean -C $(minilibx_path)

fclean:
	make clean -C $(minilibx_path)
	rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
	rm -rf $(minilibx)

re: fclean all
