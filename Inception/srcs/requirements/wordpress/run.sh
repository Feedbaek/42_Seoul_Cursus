docker stop wordpress_app
docker rm wordpress_app
docker rmi my_wordpress

#Docker build (Dockerfile) /docker/wordpress/config
docker build -t my_wordpress .

#wordpress_app 컨테이너를 백그라운드 데몬으로 http 포트를 연동하여 실행한다. HostOS인 Debian의 /docker/wordpress/data 폴더를 컨테이너의 wordpress 폴더에 마운트한다.
docker run -d --name wordpress_app -v /docker/wordpress/data:/var/www/localhost/htdocs/wordpress --net=bridge my_wordpress

