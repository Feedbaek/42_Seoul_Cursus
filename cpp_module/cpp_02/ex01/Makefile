# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 15:34:39 by minskim2          #+#    #+#              #
#    Updated: 2022/04/13 15:35:03 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed.cpp
HEADER = ./
NAME = a.out
OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ -I$(HEADER)

$(NAME): $(OBJECTS)
	$(CXX) $^ -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
