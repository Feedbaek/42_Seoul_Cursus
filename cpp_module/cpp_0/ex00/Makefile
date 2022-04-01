# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 16:18:04 by minskim2          #+#    #+#              #
#    Updated: 2022/04/01 16:30:42 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
NAME = megaphone
OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CCPP) -c $^ -o $@

$(NAME): $(OBJECTS)
	$(CCPP) $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
