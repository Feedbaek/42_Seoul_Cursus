FROM alpine:3.16

RUN apk update && apk upgrade && \
	apk add dumb-init bash curl less vim ca-certificates git tzdata zip ssmtp \
	libmcrypt-dev zlib-dev gmp-dev \
	freetype-dev libjpeg-turbo-dev libpng-dev \
	php8-fpm php8-json php8-zlib php8-xml php8-xmlwriter php8-simplexml php8-pdo php8-phar php8-openssl \
	php8-pdo_mysql php8-mysqli php8-session \
	php8-gd php8-iconv php8-gmp php8-zip \
	php8-curl php8-opcache php8-ctype php8-apcu \
	php8-intl php8-bcmath php8-dom php8-mbstring php8-xmlreader mysql-client curl && apk add -u musl && \
	rm -rf /var/cache/apk/*

ADD conf/start_wordpress.sh /home/start_wordpress.sh
RUN chmod +x /home/start_wordpress.sh && \
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp-cli

ADD conf/www.conf /etc/php8/php-fpm.d/

ENTRYPOINT ["/usr/bin/dumb-init","--","/home/start_wordpress.sh"]
