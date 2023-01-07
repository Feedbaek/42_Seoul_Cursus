#!/bin/sh

wp-cli core download --locale=en_GB --path=/var/www/html

wp-cli config create --force --dbname=$MY_MYSQL_DATABASE --dbuser=$MY_MYSQL_USER --dbpass=$MY_MYSQL_PASSWORD --dbhost=$MY_MYSQL_HOST --path=/var/www/html

wp-cli core install --url=$DOMAIN_NAME --title="WordPress Website Title" --admin_user=$ADMIN_USER --admin_password=$ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL --path=/var/www/html

#wp-cli user create $REG_USER $REG_EMAIL --user_pass=$REG_PASSWORD --path=/var/www/html

php-fpm8 -F
