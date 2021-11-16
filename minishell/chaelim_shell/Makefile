# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 00:43:43 by chalim            #+#    #+#              #
#    Updated: 2021/08/08 16:15:47 by chalim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	= 	main.c \
			exec/exec.c \
			\
			builtins/cd.c \
			builtins/echo.c \
			builtins/env.c \
			builtins/exit.c \
			builtins/export.c \
			builtins/pwd.c \
			builtins/unset.c \
			\
			utils/utils.c \
			utils/utils_env.c \
			\
			error/exec_error.c \
			\
			redirect/redirect.c \
			redirect/check_redir.c \
			redirect/check_redir_utils.c \
			redirect/make_str.c \
			\
			parse/parse_pipe.c \
			parse/parse_split.c \
			parse/parse_cmd.c \
			parse/parse_cmd_util.c \
			\
			signal.c \
			prompt.c \
			string_util.c \
			press_arrow.c \
			term.c \
			history.c \
			cursor.c

LIBFT	=	libft.a
OBJECTS	=	$(SRCS:.c=.o)
LIBS	=	-L./Libft -lft
HEADER	=	-I./
FLAG	= 	-Wall -Wextra -Werror
CC		=	gcc
RM		=	rm -rf
DEBUG	=	-g -fsanitize=address

all		: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./Libft

$(NAME)	: $(LIBFT) ${OBJECTS}
	@$(CC) $(FLAG) $(OBJECTS) $(LIBS) $(HEADER) $(DEBUG) -o $(NAME) -lft -lncurses -ledit

%.o: %.c
	@$(CC) $(FLAG) -c $^ -o $@ $(HEADER)

clean	:
	$(MAKE) -C ./Libft clean
	rm -rf ${OBJECTS}

fclean	:
	$(MAKE) -C ./Libft fclean
	rm -rf $(NAME) ${OBJECTS}

re		: fclean all

.PHONY: all clean fclean re
