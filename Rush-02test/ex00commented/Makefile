NAME = rush-02

SRC = main.c ft_utils.c ft_print.c ft_print_aux.c ft_list.c

OBJS = ${SRC:.c=.o}

CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror


$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
