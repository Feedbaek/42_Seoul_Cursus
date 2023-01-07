docker stop wordpress_db
docker rm wordpress_db
docker rmi my_mariadb

docker build -t my_mariadb .
#docker run -d --name wordpress_db -v /docker/mariadb/data:/var/lib/mysql --net=bridge my_mariadb
docker run --name wordpress_db my_mariadb
