docker stop wordpress_app
docker rm wordpress_app
docker rmi my_wordpress

#Docker build (Dockerfile) /docker/wordpress/config
docker build -t my_wordpress .

#wordpress_app 컨테이너를 백그라운드 데몬으로 http 포트를 연동하여 실행한다. HostOS인 Debian의 /docker/wordpress/data 폴더를 컨테이너의 wordpress 폴더에 마운트한다. 이미지는 infraadmin.tech:1.0을 사용한다.
docker run -d --name wordpress_app -v /docker/wordpress/data:/var/www/localhost/htdocs/wordpress --net=bridge my_wordpress
#docker run -e VIRTUAL_HOST=minskim2.42.fr --name wordpress_app -p 9000:9000 -v /docker/wordpress/data:/var/www/localhost/htdocs/wordpress my_wordpress

#docker run -d --name wordpress_app -p 9000:9000 my_wordpress

docker ps
#docker exec -it wordpress_app /bin/sh
#cd /var/www/localhost/htdocs
#wget http://wordpress.org/latest.tar.gz
#tar -xzvf latest.tar.gz
#rm latest.tar.gz
##default lighttpd.conf는 관리를 위해 HostOS로 복사해온다.
#cp /etc/lighttpd/lighttpd.conf /var/www/localhost/htdocs/wordpress
#exit
