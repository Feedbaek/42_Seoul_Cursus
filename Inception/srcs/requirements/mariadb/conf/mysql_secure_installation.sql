-- sincd mariadb 10.5, native, socket are Ok, native authorization root password change
ALTER USER root@localhost IDENTIFIED VIA mysql_native_password USING PASSWORD('1436');

-- '@localhost' ananymous delete
DELETE FROM mysql.user WHERE User='';

-- testdb delete
DROP DATABASE IF EXISTS test;
DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';

-- flush
FLUSH PRIVILEGES;
