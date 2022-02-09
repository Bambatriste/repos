SERVER_NAME = server

SERVER_SRCS = server.c\

SERVER_OBJS = ${SERVER_SRCS:.c=.o}

CLIENT_NAME = client

CLIENT_SRCS = client.c

CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}

CC = clang

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g

NAME = minitalk

all : $(NAME)

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME)

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

$(SERVER_NAME): ${SERVER_OBJS}
		make -C libft
		${CC} -o ${SERVER_NAME} ${SERVER_OBJS} ${LIBFT}

$(CLIENT_NAME): ${CLIENT_OBJS}
		make -C libft
		${CC} -o ${CLIENT_NAME} ${CLIENT_OBJS} ${LIBFT}

clean :
		rm -rf ${SERVER_OBJS} $(CLIENT_OBJS)
		make clean -C libft

fclean: clean
		rm -rf ${SERVER_NAME} $(CLIENT_NAME)
		make fclean -C libft

re:		fclean all

.PHONY: all clean fclean re
