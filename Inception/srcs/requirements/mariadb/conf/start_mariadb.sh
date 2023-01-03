#!/bin/sh

# rc pid 실행을 수행한다.
rc default

# datadir에 기본 셋업을 진행한다.
/etc/init.d/mariadb setup

# SQL 쿼리문을 넣기위해 잠시 실행한다.
rc-service mariadb start

# wordpress database 생성 SQL문
mysql -u root < /home/create_wordpressdb_user.sql

# mysql_secure_installation 설정이 담긴 sql쿼리문
mysql -u root < /home/mysql_secure_installation.sql

rc-service mariadb stop

# ForeGround로 실행한다.
/usr/bin/mysqld_safe
