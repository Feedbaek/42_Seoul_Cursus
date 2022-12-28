# alpine 3.15 Version을 기반으로 한다.
FROM alpine:3.15

# no-cache 옵션은 /var/cache/apk/* 에 garbage가 남지 않음.
# alpine3.15 기준 mariadb-10.6.8-r0 LTS
# SQL문을 직접 넣기위해 client 필요
# /etc/init.d/mariadb setup 이후 mysqld 재시작을 위해 openrc 필요
RUN apk add --no-cache mariadb mariadb-client openrc

# mysql_secure_installation 설정이 담긴 sql쿼리문
COPY conf/mysql_secure_installation.sql /home/

# sql server 설정 since alpine 3.9 First Global config file, main directives
COPY conf/mariadb-server.cnf /etc/my.cnf.d/

# wordpress database 설정
COPY conf/create_wordpressdb_user.sql /home/

# sql 시작 스크립트
COPY conf/start_mariadb.sh /home

VOLUME ["/var/lib/mysql"]

# DBMS포트는 8475를 사용한다.
EXPOSE 8475
ENTRYPOINT sh /home/start_mariadb.sh
