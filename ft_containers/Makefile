# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2022/07/20 11:34:54 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
NEWSRCS = new_main.cpp
HEADER = ./
NAME = a.out
OBJECTS = $(SRCS:.cpp=.o)
NEWOBJECTS = $(NEWSRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@ -I$(HEADER)

$(NAME): $(OBJECTS)
	$(CXX) $^ -o $@

test: $(NEWOBJECTS)
	$(CXX) $^ -o $@

clean:
	rm -rf $(OBJECTS)
	rm -rf $(NEWOBJECTS)

fclean: clean
	rm -rf $(NAME)
	rm -rf test
	rm -rf *.log

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
