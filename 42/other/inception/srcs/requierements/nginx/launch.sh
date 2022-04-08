#!/bin/bash

docker build -t test . && docker run -dit test;
id=$(docker ps | awk 'NR==2{print $1}');
echo $id;
docker exec -it $id bash

