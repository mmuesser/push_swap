NAME = push_swap

NAME_BONUS = checker

SRCS = operations.c ft_atoi.c gest_pile.c check_arg.c utils.c

SRCS_MANDATORY = main_push_swap.c tri_a.c count_mouv.c set_piles.c pretri.c \
				push_swap.c calcul_mediane.c

SRCS_BONUS = bonus/check_pile.c bonus/checker.c bonus/create_list_op.c \
			 bonus/do_op.c bonus/utils.c bonus/utils_2.c bonus/main_checker.c

INCLUDES = -I ./

INCLUDES_BONUS = -I ./bonus/

OBJS = ${SRCS:.c=.o}

OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -g3

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_MANDATORY}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MANDATORY} ${INCLUDES}

${NAME_BONUS}:	${OBJS} ${OBJS_BONUS}
				${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS} ${OBJS_BONUS} ${INCLUDES_BONUS}

all:		${NAME} ${NAME_BONUS}

bonus:		${NAME_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_MANDATORY} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus