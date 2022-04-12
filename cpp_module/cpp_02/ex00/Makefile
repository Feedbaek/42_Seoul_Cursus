# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 16:03:39 by minskim2          #+#    #+#              #
#    Updated: 2022/04/12 21:36:51 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
HEADER = ./
NAME = haha
OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CCXX) $(CPPFLAGS) -c $^ -o $@ -I$(HEADER)

$(NAME): $(OBJECTS)
	$(CCXX) $^ -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
