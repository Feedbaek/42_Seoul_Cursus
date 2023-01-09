# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2022/12/29 11:34:54 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: run

mariadb:
	sudo docker stop mariadb | \
	sudo docker rm mariadb | \
	sudo docker build -t mariadb ./srcs/requirements/mariadb/

wordpress:
	sudo docker stop wordpress | \
	sudo docker rm wordpress | \
	sudo docker build -t wordpress ./srcs/requirements/wordpress/

nginx:
	sudo docker stop nginx | \
	sudo docker rm nginx | \
	sudo docker build -t nginx ./srcs/requirements/nginx/

build: mariadb wordpress nginx

run:
	cd srcs/ && docker compose up


clean:
	cd srcs/ && docker compose down


fclean: clean
	sudo rm -rf /home/minskim2/data/
	docker rmi srcs-mariadb | docker rmi srcs-wordpress | docker rmi srcs-nginx

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
