NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRCS = ft_printf.c checks.c converts.c utils.c convert_d.c convert_s.c convert_u.c convert_x.c convert_p.c convert_c.c fill_buffer.c

CC = gcc

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

.c.o : 
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

$(NAME): ${OBJS}
		make -C libft
		cp ${LIBFT} ${NAME}
		ar rcs ${NAME} ${OBJS}

clean :
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
