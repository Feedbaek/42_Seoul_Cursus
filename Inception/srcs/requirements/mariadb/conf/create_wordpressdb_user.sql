-- database 생성
create database wordpress;

-- database 유저생성
create user 'wordpressuser'@'%' identified by '1436';

-- database 권한
GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER, CREATE TEMPORARY TABLES, CREATE VIEW, EVENT, TRIGGER, SHOW VIEW, CREATE ROUTINE, ALTER ROUTINE, EXECUTE ON wordpress.* TO 'wordpressuser'@'%';

-- 적용
FLUSH PRIVILEGES;
