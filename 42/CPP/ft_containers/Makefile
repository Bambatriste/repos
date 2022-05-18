NAME = containers

SRCS = m.cpp

CPPC = clang++

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Wextra -Werror -std=c++11 -g3

all : $(NAME)

.cpp.o :
		${CPPC} ${CPPFLAGS} -c $< -o ${<:.cpp=.o} 

$(NAME): ${OBJS}
		${CPPC} -o ${NAME} ${OBJS}
clean :
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
