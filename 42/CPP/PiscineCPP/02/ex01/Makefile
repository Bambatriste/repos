NAME = Fixednbrs

SRCS = main.cpp\
		Fixed.cpp\

CC = c++

OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

.cpp.o :
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o} 

$(NAME): ${OBJS}
		${CC} -o ${NAME} ${OBJS}
clean :
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
