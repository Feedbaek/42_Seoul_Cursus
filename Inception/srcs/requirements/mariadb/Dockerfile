# alpine 3.16 Version을 기반으로 한다.
FROM alpine:3.16

# no-cache 옵션은 /var/cache/apk/* 에 garbage가 남지 않음.
# alpine3.16 기준 mariadb-10.6.8-r0 LTS
# SQL문을 직접 넣기위해 client 필요
RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client dumb-init

# mysql_secure_installation 설정이 담긴 sql쿼리문
#COPY conf/mysql_secure_installation.sql /home/

# sql server 설정 since alpine 3.9 First Global config file, main directives
COPY conf/mariadb-server.cnf /etc/my.cnf.d/
RUN chmod 755 /etc/my.cnf.d/mariadb-server.cnf

# wordpress database 설정
#COPY conf/create_wordpressdb_user.sql /home/

# sql 시작 스크립트
COPY conf/start_mariadb.sh /home


RUN chmod 777 /home/start_mariadb.sh


#chmod 777 /usr/bin/mysqld_safe && \
#RUN chmod 777 /var/lib/mysql
#chmod +x /run/mysqld && \Q

#USER maria
#WORKDIR /home/maria

#VOLUME ["/var/lib/mysql"]

# DBMS포트는 3306을 사용한다.
#EXPOSE 3306
ENTRYPOINT ["/usr/bin/dumb-init", "--", "/home/start_mariadb.sh"]
