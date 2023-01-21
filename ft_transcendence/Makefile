# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2023/01/21 17:11:19 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: run

run:
	mkdir -p ~/ft_transcendence
	cd srcs && docker-compose up --build


clean:
	cd srcs && docker-compose down

fclean: clean
	docker rmi srcs_nestjs
	docker volume rm srcs_nestjs_volume

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
