NAME = push_swap

SOURCE = operations.c calcul_mediane.c ft_atoi.c gest_pile.c push_swap.c \
			tri_a.c check_arg.c pretri.c set_piles.c utils.c count_mouv.c

INCLUDES = -I includes/

OBJS = ${SOURCE:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${INCLUDES}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re