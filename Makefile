NAME = push_swap

NAME_BONUS = checker

SOURCE = operations.c calcul_mediane.c ft_atoi.c gest_pile.c push_swap.c \
			tri_a.c check_arg.c pretri.c set_piles.c utils.c count_mouv.c

SOURCE_BONUS = bonus/check_pile.c bonus/checker.c bonus/create_list_op.c bonus/do_op.c bonus/utils.c

INCLUDES = -I ./

INCLUDES_BONUS = -I bonus/

OBJS = ${SOURCE:.c=.o}

OBJS_BONUS = ${SOURCE_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${INCLUDES}

${NAME_BONUS}:	${OBJS_BONUS}
			${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${INCLUDES_BONUS}

all:		${NAME}

bonus:		${NAME_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus