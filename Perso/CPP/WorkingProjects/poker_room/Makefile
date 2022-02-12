NAME = Pokeroom

SRCS = srcs/main.cpp\
		srcs/card/Card.cpp\
		srcs/deck/Deck.cpp


CC = clang++

OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++11

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
