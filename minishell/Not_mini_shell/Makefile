# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 15:50:35 by minskim2          #+#    #+#              #
#    Updated: 2022/03/30 17:09:37 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRCS = srcs/main.c \
		srcs/builtins/ft_echo.c \
		srcs/builtins/ft_cd.c \
		srcs/builtins/ft_pwd.c \
		srcs/builtins/ft_export.c \
		srcs/builtins/ft_unset.c \
		srcs/builtins/ft_env.c \
		srcs/builtins/ft_exit.c \
		srcs/prompts/prompt.c \
		srcs/prompts/parser.c \
		srcs/prompts/process_env_var.c \
		srcs/prompts/parse_utils.c \
		srcs/prompts/parse_utils2.c \
		srcs/prompts/exec_function.c \
		srcs/utils/cpy_env.c \
		srcs/utils/free_double_pointer.c \
		srcs/utils/malloc_error.c \
		srcs/utils/termios.c \
		srcs/utils/equals.c \
		srcs/utils/do_export.c \
		srcs/signal/signal.c \
		srcs/pipex/gnl/get_next_line_utils.c \
		srcs/pipex/gnl/get_next_line_utils2.c \
		srcs/pipex/gnl/get_next_line.c \
		srcs/pipex/path_finder.c \
		srcs/pipex/pipex_split.c \
		srcs/pipex/pipex_strjoin.c \
		srcs/pipex/redirect.c \
		srcs/pipex/utils.c \
		srcs/pipex/here_doc.c \
		srcs/pipex/pipex.c

SRCS_BONUS =

HEADER = $(shell pwd)/include
OBJECTS = $(SRCS:.c=.o)
OBJECTS_TEST = $(TEST_SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_LDIR	= $(shell pwd)/Libft
FT_LIBFT 	= $(LIBFT_LDIR)/libft.a
LIBFT_NAME	= ft
LIBFT_LIB	= -L$(LIBFT_LDIR) -l$(LIBFT_NAME)

RL_LINKING = -lreadline -L${HOME}/.brew/opt/readline/lib
RL_COMPILE = -I${HOME}/.brew/opt/readline/include

ifdef WITH_BONUS
	NAME = minishell_bonus
	OBJS = $(OBJECTS_BONUS)
else
	ifdef WITH_TEST
		NAME = minishell_test
		OBJS = $(OBJECTS_TEST)
	else
		NAME = minishell
		OBJS = $(OBJECTS)
	endif
endif

all: $(NAME)

test:
	make WITH_TEST=1 all

bonus:
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus test

%.o: %.c
	$(CC) -c $^ -o $@ -I$(HEADER) $(RL_COMPILE)

$(FT_LIBFT):
	make -C $(LIBFT_LDIR)

$(NAME): $(FT_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(RL_LINKING) $(LIBFT_LIB)

clean:
	make -C $(LIBFT_LDIR) clean
	rm -rf $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_TEST)

fclean: clean
	make -C $(LIBFT_LDIR) fclean
	rm -rf minishell minishell_bonus minishell_test

re: fclean all

debug: $(FT_LIBFT)
	$(CC) -g -fsanitize=address $(SRCS) -o $(NAME) $(RL_LINKING) $(RL_COMPILE) $(LIBFT_LIB) -I$(HEADER)
