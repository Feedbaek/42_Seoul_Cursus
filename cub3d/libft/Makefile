# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 02:48:32 by donghyki          #+#    #+#              #
#    Updated: 2022/06/10 21:21:40 by donghyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a

SRCS =		ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoabase.c \
			get_next_line.c \
			ft_putstr.c \
			ft_exit.c \
			ft_isformat.c \
			ft_free2d.c \
			ft_isdigit_str.c \
			ft_cntword.c

B_SRCS =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstmaxwidth.c

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${B_SRCS:.c=.o}

INC			= ./

CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -f
ECHO		= echo

$(NAME):	${OBJS}
			@${AR} ${ARFLAGS} $@ $^

%.o: %.c
			@${CC} -c ${CFLAGS} -o $@ $< -I${INC}

all:		${NAME}

clean:
			@${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

bonus:		${OBJS} ${B_OBJS}
			@${AR} ${ARFLAGS} ${NAME} $^

.PHONY: 	all clean fclean re bonus
