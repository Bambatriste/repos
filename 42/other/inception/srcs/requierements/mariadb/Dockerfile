FROM debian:buster

RUN apt-get update -y;\
    apt-get upgrade -y;\
    apt-get install -y mariadb-server;

COPY entrypoint.sh /

COPY 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["bash", "/entrypoint.sh"]

