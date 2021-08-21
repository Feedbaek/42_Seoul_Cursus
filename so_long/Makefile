# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 18:16:02 by minskim2          #+#    #+#              #
#    Updated: 2021/08/21 15:54:14 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -Werror -Wextra -Wall
NAME = so_long
minilibx_path = srcs/minilibx_mms_20210621
minilibx = libmlx.dylib
SRCS = srcs/so_long.c \
	srcs/init.c \
	srcs/key_input.c \
	srcs/tools.c \
	srcs/draw.c \
	srcs/search.c \
	srcs/setting.c \
	srcs/map_parse.c \
	srcs/gnl/get_next_line.c \
	srcs/gnl/get_next_line_utils.c \
	srcs/gnl/get_next_line_utils2.c
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
	$(CC) $(CFLAGS) -g -L ./$(minilibx_path) -lmlx -framework OpenGL -framework AppKit $^ -o $@
	install_name_tool -change $(minilibx) $(minilibx_path)/$(minilibx) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $^ -o $@ -I $(HEADER) -I $(minilibx_path)

make_mini:
	make -C $(minilibx_path)

bonus:
	make WITH_BONUS=1 all

clean:
	make clean -C $(minilibx_path)
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean:
	make clean -C $(minilibx_path)
	rm -rf $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean all

test: re
	./$(NAME) map1.ber
