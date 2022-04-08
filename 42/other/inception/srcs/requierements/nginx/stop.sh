#!/bin/bash

id=$(docker ps | awk 'NR==2{print $1}');
echo $id;
docker stop $id

