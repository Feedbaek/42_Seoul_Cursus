docker stop wordpress_server
docker rm wordpress_server
docker rmi my_nginx

docker build -t my_nginx .
docker run -d --name wordpress_server -p 443:443 -v /docker/nginx/data:/var/lib/mysql --net=bridge my_nginx
