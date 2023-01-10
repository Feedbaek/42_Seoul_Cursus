# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 18:04:36 by minskim2          #+#    #+#              #
#    Updated: 2023/01/10 21:34:42 by minskim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: run

# wsl2에서 systemd을 사용할 수 없기 때문에 service로 도커 서버 실행
dockerd:
	sudo service docker start | sleep 3
	sudo chmod 666 /var/run/docker.sock
	sudo sh -c "echo '127.0.0.1 minskim2.42.fr' >> /etc/hosts"

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
	mkdir -p /home/minskim2/data/mariadb
	mkdir -p /home/minskim2/data/wordpress
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
