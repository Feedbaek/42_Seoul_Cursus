# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2023/01/19 19:12:49 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: run

run:
	cd srcs && docker compose up
#mkdir -p ~/data/


clean:
	cd srcs && docker compose down

fclean: clean
	docker rmi srcs-nestjs
#rm -rf /home/minskim2/data/

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
