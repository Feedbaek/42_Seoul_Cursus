# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2023/01/20 15:33:32 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: run

run:
	mkdir -p ~/ft_transcendence
	cd srcs && docker compose up


clean:
	cd srcs && docker compose down

fclean: clean
	docker rmi srcs-nestjs
	docker volume rm srcs_nestjs_volume

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
