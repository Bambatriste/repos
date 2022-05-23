#!/bin/bash

g++ mazoise_main.cpp && ./a.out > ft_mazoise.log
rm a.out
g++ -D=STD mazoise_main.cpp && ./a.out > std_mazoise.log

rm diff_mazoise.log

diff   std_mazoise.log ft_mazoise.log > diff_mazoise.log;

if [ -s diff_mazoise.log ]; then
    echo "Errors found";
else
    echo "OK";
fi
