FROM alpine:3.16

ENV TERM="xterm" \
	DB_HOST="172.17.0.:3306" \
	DB_NAME="wordpress" \
	DB_USER="wordpressuser"\
	DB_PASS="1436"

RUN apk add dumb-init bash curl less vim ca-certificates git tzdata zip \
	libmcrypt-dev zlib-dev gmp-dev \
	freetype-dev libjpeg-turbo-dev libpng-dev \
	php8-fpm php8-json php8-zlib php8-xml php8-xmlwriter php8-simplexml php8-pdo php8-phar php8-openssl \
	php8-pdo_mysql php8-mysqli php8-session \
	php8-gd php8-iconv php8-gmp php8-zip \
	php8-curl php8-opcache php8-ctype php8-apcu \
	php8-intl php8-bcmath php8-dom php8-mbstring php8-xmlreader mysql-client curl && apk add -u musl && \
	rm -rf /var/cache/apk/*

#RUN sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' /etc/php8/php.ini && \
#	sed -i 's/expose_php = On/expose_php = Off/g' /etc/php8/php.ini && \
	#sed -i "s/nginx:x:100:101:nginx:\/var\/lib\/nginx:\/sbin\/nologin/nginx:x:100:101:nginx:\/usr:\/bin\/bash/g" /etc/passwd && \
	#sed -i "s/nginx:x:100:101:nginx:\/var\/lib\/nginx:\/sbin\/nologin/nginx:x:100:101:nginx:\/usr:\/bin\/bash/g" /etc/passwd- && \
	#ln -s /sbin/php-fpm7 /sbin/php-fpm

RUN adduser -D wordpress
#USER wordpress

ADD conf/start_wordpress.sh /home/start_wordpress.sh
RUN chmod +x /home/start_wordpress.sh && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp-cli && \
	chown wordpress:wordpress /usr/bin/wp-cli

RUN mkdir -p /usr/html && chown -R wordpress:wordpress /usr/html

RUN cd /usr/html && wp-cli core download --locale=en_GB && \
	wp-cli config create --dbname=wordpress --dbuser=wordpressuser --dbpass=1436 --dbhost=172.17.0.2:3306 && \
	wp-cli core install --url=minskim2.42.fr  --title="WordPress Website Title" --admin_user=wordpress --admin_password=1436 --admin_email="minskim2@student.42seoul.kr"
ADD conf/php-fpm.conf /etc/php8/
ADD conf/www.conf /etc/php8/php-fpm.d/

#EXPOSE 9000
VOLUME ["/usr/html"]

ENTRYPOINT ["/usr/bin/dumb-init","--","/home/start_wordpress.sh"]
