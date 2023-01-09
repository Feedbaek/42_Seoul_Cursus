#!/bin/sh

# mysql 데이터 디렉토리 초기화

if [ ! -d /var/lib/mysql/$MARIADB_DATABASE ]; then
	mysql_install_db --user=mysql --datadir=/var/lib/mysql/

	mkdir -p /run/mysqld/
	chown -R mysql:mysql /var/lib/mysql/ /run/mysqld/

	chmod 777 /var/lib/mysql

	# BackGround로 실행한다.
	/usr/bin/mysqld_safe --user=mysql --datadir=/var/lib/mysql/ &

	sleep 1


	# ===================================================

	# wordpress database 생성 SQL문

	# database 생성
	mysql -e "create database $MARIADB_DATABASE;"

	# database 유저 생성
	mysql -e "create user '$MARIADB_USER'@'%' identified by '$MARIADB_PASSWORD';"

	# database 권한
	mysql -e "GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER, CREATE TEMPORARY TABLES, CREATE VIEW, EVENT, TRIGGER, SHOW VIEW, CREATE ROUTINE, ALTER ROUTINE, EXECUTE ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%';"

	# 적용
	mysql -e "FLUSH PRIVILEGES;"

	# =====================================================

	# mysql_secure_installation 설정이 담긴 sql쿼리문

	# -- mariadb 10.5부터 native, socket 인증방식 동시사용가능, native인증으로 고정 및 root 패스워드 변경
	mysql -e "ALTER USER root@localhost IDENTIFIED VIA mysql_native_password USING PASSWORD('$MARIADB_ROOT_PASSWORD'); \
	DELETE FROM mysql.user WHERE User=''; \
	DROP DATABASE IF EXISTS test; \
	DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%'; \
	FLUSH PRIVILEGES;"


	# -- '@localhost' 익명연결 허용 삭제
	#mysql -e "DELETE FROM mysql.user WHERE User='';"

	# -- testdb 삭제
	#mysql -e "DROP DATABASE IF EXISTS test;"
	#mysql -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';"

	# -- 적용
	#mysql -e "FLUSH PRIVILEGES;"


	# mysqld_safe BackGround 종료
	mysqladmin -u root --password=$MARIADB_ROOT_PASSWORD shutdown

fi
# ForeGround로 실행한다.
/usr/bin/mysqld_safe --user=mysql --datadir=/var/lib/mysql/

