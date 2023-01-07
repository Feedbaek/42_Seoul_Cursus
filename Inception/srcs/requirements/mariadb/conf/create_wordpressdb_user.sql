-- create database
create database wordpress;

-- create database user
create user 'wordpressuser'@'%' identified by '1436';

-- privileges database
GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER, CREATE TEMPORARY TABLES, CREATE VIEW, EVENT, TRIGGER, SHOW VIEW, CREATE ROUTINE, ALTER ROUTINE, EXECUTE ON wordpress.* TO 'wordpressuser'@'%';

-- flush
FLUSH PRIVILEGES;
