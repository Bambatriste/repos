FROM debian:buster

RUN apt-get update -y > /dev/null;\
    apt-get upgrade -y > /dev/null;\
    apt-get install nginx -y > /dev/null;\
    mkdir etc/ssl;\
    mkdir etc/ssl/private;

COPY nginx.conf ./etc/nginx/nginx.conf

COPY default ./etc/nginx/sites-available/default

COPY nginx.crt /etc/ssl/certs/nginx.crt

COPY nginx.key /etc/ssl/private/nginx.key

CMD ["nginx", "-g", "daemon off;"]

