FROM debian:buster

RUN apt-get update

RUN apt-get upgrade

RUN apt-get install nginx -y

RUN apt-get install vim -y

RUN apt-get install mariadb-server -y

RUN apt-get install -y php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline

RUN apt-get install -y php-mbstring php-zip php-gd

RUN apt-get install -y php-mysql

COPY srcs ./root

WORKDIR /root/

EXPOSE 443

EXPOSE 80

CMD			mkdir ../var/www/localhost\
			&& cp -r wordpress /var/www/localhost/wordpress\
			&& cp -r phpmyadmin /var/www/localhost/phpmyadmin\
			#&& cp wp-config.php /var/www/local/wordpress/wp-config.php\
			&& cp default /etc/nginx/sites-enabled/default\
			&& service nginx start\
			&& service mysql start\
			&& service php7.3-fpm start\
			&& echo "CREATE DATABASE wordpress;" | mariadb\
			&& echo "GRANT ALL ON wordpress.* TO 'user'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;" | mariadb\
			&& echo "FLUSH PRIVILEGES;" | mariadb\
			&& bash
