# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 00:53:18 by minskim2          #+#    #+#              #
#    Updated: 2022/04/10 01:41:38 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
HEADER = ./
NAME = horde
OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CCPP) $(CPPFLAGS) -c $^ -o $@ -I$(HEADER)

$(NAME): $(OBJECTS)
	$(CCPP) $(CPPFLAGS) -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
