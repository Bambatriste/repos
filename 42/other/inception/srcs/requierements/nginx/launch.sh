#!/bin/bash

docker build -t test . && docker run -p 8080:80 test;
id=$(docker ps | awk 'NR==2{print $1}');
echo $id;
docker exec -it $id bash

