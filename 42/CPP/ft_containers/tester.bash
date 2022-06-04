#!/bin/bash


make fclean
make CPPFLAGS='-Wall -Wextra -Werror -g3 -std=c++98 -D STD' NAME='std.out';
make fclean;
make CPPFLAGS='-Wall -Wextra -Werror -g3 -std=c++98' NAME='ft.out';

rm std.log ft.log diff.log;

./std.out > std.log;
./ft.out > ft.log;

diff std.log ft.log > diff.log;

if [ -s diff.log ]; then
    echo "Errors found";
else
    echo "OK";
fi
