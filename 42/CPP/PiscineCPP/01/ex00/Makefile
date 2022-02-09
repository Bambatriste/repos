NAME = Zombies

SRCS = Zombie.cpp\
		main.cpp\
		newZombie.cpp\
		randomChump.cpp\

CC = clang++

OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98

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
