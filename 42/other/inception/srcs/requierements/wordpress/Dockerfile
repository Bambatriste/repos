FROM debian:buster

RUN apt-get update -y > /dev/null;\
    apt-get install -y vim php-fpm mariadb-client php-mysql curl > /dev/null;

COPY ./www.conf /etc/php/7.3/fpm/pool.d/

COPY entrypoint.sh .

COPY wp-config.php .

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar;\
    chmod +x wp-cli.phar;\
    mv wp-cli.phar /usr/bin/wp

VOLUME /var/www/html

ENTRYPOINT ["bash", "/entrypoint.sh"]
