FROM debian:buster

RUN apt-get update -y;\
    apt-get upgrade -y;\
    apt-get install -y mariadb-server;\
    apt-get install -y mariadb-client;

RUN mkdir -p /var/run/mysqld/
run mkdir -p /run/mysqld/ && chown -R mysql:root /run/mysqld

COPY entrypoint.sh /

COPY ./sql_config.sql /tmp

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

VOLUME /var/lib/mysql

ENTRYPOINT ["bash", "/entrypoint.sh"]

