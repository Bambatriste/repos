FROM debian:buster

RUN apt-get update -y;\
    apt-get upgrade -y;\
    apt-get install nginx -y;\
    mkdir etc/ssl;\
    mkdir etc/ssl/private;

RUN apt-get install vim -y;

COPY nginx.conf ./etc/nginx/nginx.conf

COPY default ./etc/nginx/sites-available/default

COPY nginx.crt /etc/ssl/certs/nginx.crt

COPY nginx.key /etc/ssl/private/nginx.key

CMD ["nginx", "-g", "daemon off;"]

