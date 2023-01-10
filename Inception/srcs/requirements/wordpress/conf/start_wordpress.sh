#!/bin/sh

if [ ! -d /var/www/html/wp-admin ]; then

sleep 2

wp-cli core download --locale=ko_KR --path=/var/www/html

wp-cli config create --force --dbname=$MARIADB_DATABASE --dbuser=$MARIADB_USER --dbpass=$MARIADB_PASSWORD --dbhost=$MARIADB_HOST --path=/var/www/html

wp-cli core install --url=$DOMAIN_NAME --title="WordPress Website Title" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --path=/var/www/html

wp-cli user create $REG_USER $REG_EMAIL --user_pass=$REG_PASSWORD --path=/var/www/html

fi

php-fpm8 -F
