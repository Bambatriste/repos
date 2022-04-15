FROM debian:buster

RUN apt-get update -y > /dev/null;\
    apt-get upgrade -y > /dev/null;\
    apt-get install -y mariadb-server \
	procps \
	mariadb-client > /dev/null;\
    chmod 777 /var/lib/mysql;

RUN mkdir -p /var/run/mysqld/
RUN mkdir -p /run/mysqld/ && chown -R mysql:root /run/mysqld

COPY entrypoint.sh /

COPY ./sql_config.sql /tmp

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

VOLUME /var/lib/mysql

ENTRYPOINT ["bash", "/entrypoint.sh"]

